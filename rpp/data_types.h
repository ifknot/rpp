#pragma once

#include <variant>
#include <string>
#include <ctime>
#include <array>
#include <complex>

#include "constants.h"

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
	 * The 6 basic R-ish data types (raw, character, numeric, integer, logical, complex
	 * @note to avoid confusion between character and string in C++ domain "string_t" is used
	 */
	using r_raw = char;
	using r_string = std::string;
	using r_numeric = double;
	using r_integer = int;
	using r_complex = std::complex<double>;

	/**
	 * A separate logical type to prevent C++ implicitly (i.e. silently) coercing bool to integer!
	 */
	struct r_logical {
		bool boolean;
	};

	/**
	 * An R-ish calender date type
	 * This is the type to use if you have only dates, but no times, in your data.
	 * Default format is "%Y-%m-%d" e.g. 2020 - 09 - 30
	 * functions: as_dates, diffdates, +, -, etc
	 */
	struct r_date {

		std::tm tm;
		std::string format{ "%Y-%m-%d" };

		bool is_equal(const r_date& rhs) const {
			auto rhs_tm = rhs.tm;
			auto lhs_tm = tm;
			return std::mktime(&lhs_tm) == std::mktime(&rhs_tm);
		}

		bool is_greater (const r_date& rhs) const {
			auto rhs_tm = rhs.tm;
			auto lhs_tm = tm;
			return std::mktime(&lhs_tm) > std::mktime(&rhs_tm);
		}

		//  TODO: operator+=
		//  TODO: operator-=

	};

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
	static const std::array<std::string, 7> index_to_string{ "raw", "int", "num", "str", "bool", "cplx", "date" };

	/**
	 * syntactic sugar
	 */
	enum ordinal_t { first = 1, second, third, fourth, fifth };

	/**
	 * R-ish implementation of not applicable (NA)
	 */
	static const r_integer NA = -1;

}