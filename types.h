#pragma once

#include <variant>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <ctime>
#include <optional>
#include <array>

namespace R {

	/**
	 *  R has basic types  "logical", "integer", "double", "complex", "character" and "raw"
	 *  but in a C++ domain using character instead of string could be confusing
	 */
	using r_integer = int;			// int32_t
	using r_double = double;		// float, double, long double
	using r_string = std::string;	// preferring string over character will help semantics in a C++ domain
	using r_raw = char;				// or unint8_t?

	static const r_integer NA = -1;	// R-ish implementation of not applicable (NA)

	/**
	 * separate logical type to prevent C++ implicitly (ie silently) coercing bool to integer!
	 */
	struct r_logical {
		bool boolean;
	};

	/**
	 * This is the type to use if you have only dates, but no times, in your data.
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

	/*
	struct POSIXlt {


	}
	*/

	/**
	 * define a variant of the R-ish PODs
	 */
	using data_variants = std::variant<r_raw, r_integer, r_double, r_string, r_logical, r_date>;

	/**
	 * std:get can use the type or index e.g. std::get<char> or std::get<0>
	 * using the data_type enumeration prevents errors from using the wrong index
	 */
	enum data_types {_raw, _int, _dbl, _str, _bool, _date};

	/**
	 * convert PODs into their string name
	 */
	static const std::array<std::string, 6> index_to_type{ "raw", "int", "dbl", "str", "bool", "date" };

	/**
	 * @brief in R vectors can store any variable type.
	 *
	 * @note unlike R, variant_vectors are limited to the data_variants defined above
	 */
	using variant_vector = std::vector<data_variants>;

	/**
	 * @brief In R factors are data objects used to categorize data and store it as levels.
	 *
	 * Stored as a pair of integer and string variant vectors they can be used to convert unique values into
	 * ordinal integers.
	 * @note unlike R factors can not be stored in a data_frame but either of the pairs variant vectors can be.
	 * The first variant_vector of the pair is the ordinal integers, the second is the levels.
	 */
	using variant_factor = std::pair<variant_vector, variant_vector>;

	/**
	 * As per R language definition the following are the characteristics of a data frame
	 *
	 * - The column names should be non-empty.
	 * - The row names should be unique.
	 * - The data stored in a data frame can be of numeric, factor or character type.
	 * - Each column should contain same number of data items.
	 */
	using data_frame = std::unordered_map<std::string, variant_vector>;

}