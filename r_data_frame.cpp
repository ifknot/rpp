#include "r_data_frame.h"

#include <fstream>
#include <regex>

namespace R {

	variant_vector as_dates(std::vector<std::string> source) {
		variant_vector tm_dates;
		for (const auto& date : source) {
			std::stringstream ss;
			ss << date + "T00:00:00Z ";
		std:tm tm;
			ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");
			tm_dates.push_back(tm);
		}
		return tm_dates;
	}

	token_t r_typeof(std::string& lexeme) {
		if (lexeme == "true" || lexeme == "false") {
			return token_t::logical_t;
		}
		if (std::regex_match(lexeme, std::regex("[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?"))) {
			try {
				auto x = std::stod(lexeme); // int or doube
				if (lexeme.find_first_not_of("+-0123456789") == std::string::npos) {
					return token_t::integer_t;
				}
				else {
					return token_t::double_t;
				}
			}
			catch (std::invalid_argument) {
				return token_t::broken_t;
			}
			catch (std::out_of_range) {
				return token_t::broken_t;
			}
		}
		if (lexeme[0] == '"' && lexeme.size() > 2 && lexeme[lexeme.size() - 1] == '"') {
			return token_t::string_t;
		}
		if (lexeme[0] == '\'' && lexeme.size() == 3 && lexeme[lexeme.size() - 1] == '\'') {
			return token_t::raw_t;
		}
		return token_t::broken_t;
	}

	data_frame read_csv(std::string file_path, bool has_header) {
		data_frame d;
		try {
			std::ifstream file(file_path);
			if (!file.is_open()) {
				throw std::ifstream::failure(file_path);
			}
			file.exceptions (std::ifstream::badbit);
			std::string line;
			size_t nline{ 1 }, nfield{ 0 };	// line number n, field number nn
			std::vector<std::string> column;
			if (has_header) {
				std::getline(file, line);
				std::istringstream iss(line);
				std::string field;
				while (getline(iss, field, ',')) {
					if (r_typeof(field) == token_t::string_t) {
						field = field.substr(1, field.size() - 2);	// chop enclosing sigils
						column.push_back(field);	// collect column name
						d[field];	// construct empty column
					}
					else {
						throw std::runtime_error(
							"record " + std::to_string(nline) + " field " + std::to_string(nfield) + " malformed string " + field
						);
					}
					nfield++;
				}
				nline++;
			}
			while (std::getline(file, line)) {
				std::istringstream iss(line);
				std::string field;
				nfield = 0;
				while (getline(iss, field, ',')) {
					switch (r_typeof(field)) {
					case token_t::logical_t:
						d[column[nfield]].push_back((field == "true") ? true : false);
						break;
					case token_t::integer_t:
						d[column[nfield]].push_back(stoi(field));
						break;
					case token_t::double_t:
						d[column[nfield]].push_back(stod(field));
						break;
					case token_t::complex_t:
						break;
					case token_t::string_t:
					case token_t::date_t:
						//std::cout << field << " " << column[nfield] << '\n';
						d[column[nfield]].push_back(field.substr(1, field.size() - 2));
						break;
					case token_t::raw_t:
						d[column[nfield]].push_back(field.substr(1, field.size() - 2));
						break;
					case token_t::broken_t:
						throw std::runtime_error(
							"broken record " + std::to_string(nline) + " field " + std::to_string(nfield) + " : " + field
						);
						break;
					}
					//std::cout << field << '\n';
					nfield++;
				}
				nline++;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		return d;
	}

}

/*-------- stream operator overloads --------*/

std::ostream& operator<<(std::ostream& os, const R::r_date& date) {
	os << std::put_time(&date, "%Y-%m-%d");
	return os;
}

std::ostream& operator<<(std::ostream& os, const R::variant_vector& vv) {
	for (const auto& v : vv) {
		std::visit([&os](auto&& arg) {os << arg << '\t'; }, v);
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const R::variant_factor& vf) {
	os << vf.first << "\n Levels: " << vf.second;
	return os;
}

std::ostream& operator<<(std::ostream& os, const R::data_frame& df) {
	size_t sz{ 0 };
	for (const auto& [key, vctr] : df) {
		os << '\t' << key;
		sz = vctr.size();
	}
	std::cout << '\n';
	for (size_t i{ 0 }; i < sz; ++i) {
		std::cout << i;
		for (const auto& [key, vctr] : df) {
			std::visit([&os](auto&& arg) {os << '\t' << arg; }, vctr[i]);
		}
		os << '\n';
	}
	return os;
}
