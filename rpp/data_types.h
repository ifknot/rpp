
#pragma once

#include <variant>
#include <string>
#include <array>
#include <complex>

#include "r_logical.h"
#include "r_date.h"

/**
 * @brief Designed to offer familiar enough semantics with their R language counterparts to facilitate R knowledge and skills transfer into the C++ domain.
 * The idea is to use std::variant with a small set of types (7) similar to those used in R to enable run time heterogeneous data types:
 * + raw
 * + string
 * + numeric
 * + integer
 * + complex
 * + logical
 * + date
 */
namespace R {

	/**
	 * The 7 basic R-ish data types (raw, character, numeric, integer, logical, complex, date)
	 * @note to avoid confusion between character and string in C++ domain "string_t" is used
	 */
	using r_raw = char;
	using r_string = std::string;
	using r_numeric = double;
	using r_integer = int;
	using r_complex = std::complex<double>;

	using r_ordinal = unsigned int;

	/**
	 * define a variant of the 7 R-ish data types
	 */
	using r_type = std::variant<r_raw, r_integer, r_numeric, r_string, r_logical, r_complex, r_date>;

	/**
	 * std:get can use the type or index e.g. std::get<char> or std::get<0>
	 * using the data_type enumeration prevents errors from using the wrong index
	 */
	enum r_index {_raw, _int, _num, _str, _bool, _cplx, _date};

	/**
	 * convert PODs into their string name
	 */
	static const std::array<r_string, 7> index_to_string{ "raw", "int", "num", "str", "bool", "cplx", "date" };

	/**
	 * syntactic sugar
	 */
	enum ordinal_t { first = 1, second, third, fourth, fifth };

	/**
	 * R-ish implementation of not applicable (NA)
	 */
	static const r_integer NA = -1;

}