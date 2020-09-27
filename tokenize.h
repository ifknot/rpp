#pragma once

#include <string>

namespace R {

	/**
	 *  R has basic types  "logical", "integer", "double", "complex", "character", "raw"
	 *  but in a C++ domain using character instead of string could be confusing
	 */
	enum class token_t { logical_t, integer_t, double_t, complex_t, string_t, raw_t, date_t, broken_t };

	/**
	 * parsing input streams requires the ability to recognize the limited R-ish PODs
	 * @note unrecognized lexemes return btoken_t
	 * 
	 * @param lexeme - the basic lexical unit to tokenize
	 */
	token_t tokenize(std::string& lexeme);

}