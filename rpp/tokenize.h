
#pragma once

#include <string>

namespace R {

	/**
	 *  The 7 R-ish data types:
	 *  r_raw, r_integer, r_numeric, r_string, r_logical, r_complex, r_date
	 *  converted to tokens with an extra 'broken' token for unrecognized type
	 */
	enum class token_t { raw_t, integer_t, numeric_t, string_t, logical_t, complex_t, date_t, broken_t };

	/**
	 * parsing input streams requires the ability to recognize the limited R-ish PODs
	 * @note unrecognized lexemes return btoken_t
	 * 
	 * @param lexeme - the basic lexical unit to tokenize
	 */
	token_t tokenize(std::string& lexeme);

}