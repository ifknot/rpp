#include "read_csv.h"

#include "tokenize.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace R {

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
					if (tokenize(field) == token_t::string_t) {
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
					switch (tokenize(field)) {
					case token_t::logical_t:
						d[column[nfield]].push_back((field == "true") ? true : false);
						break;
					case token_t::integer_t:
						d[column[nfield]].push_back(stoi(field));
						break;
					case token_t::numeric_t:
						d[column[nfield]].push_back(stod(field));
						break;
					case token_t::complex_t:
						// TODO: date_t
						break;
					case token_t::date_t:
						// TODO: date_t
					case token_t::string_t:
						d[column[nfield]].push_back(field.substr(1, field.size() - 2));
						break;
					case token_t::raw_t:
						d[column[nfield]].push_back(field.substr(1, field.size() - 2));
						break;
					case token_t::broken_t:
						throw std::runtime_error(
							file_path + " broken record on line " + std::to_string(nline) + " field " + std::to_string(nfield) + " : " + field
						);
						break;
					}
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