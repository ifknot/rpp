
#include "tokenize.h"

#include <regex>

namespace R {

	token_t tokenize(std::string& lexeme) {
		if (lexeme == "true" || lexeme == "false") {
			return token_t::logical_t;
		}
		if (std::regex_match(lexeme, std::regex("[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?"))) {
			try {
				std::stod(lexeme); // try convert 
				// if get here then int or double
				if (lexeme.find_first_not_of("+-0123456789") == std::string::npos) {
					return token_t::integer_t;
				}
				else {
					return token_t::numeric_t;
				}
			}
			//otherwise catch the exception and tokenize accordingly
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
		// TODO: complex_t
		// TODO: date_t
		return token_t::broken_t;
	}

}
