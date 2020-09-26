#pragma once

#include <variant>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <optional>
#include <math.h>
#include <stdexcept>

namespace R {

	

	/**
	 *  R has basic types  "logical", "integer", "double", "complex", "character", "raw" 
	 *  but in a C++ domain using character instead of string could be confusing 
	 */
	enum token_t {logical_t, integer_t, double_t, complex_t, string_t, raw_t, date_t, broken_t};

	using r_logical =	bool;
	using r_integer	=	int;			// int32_t
	using r_double	=	double;			// float, double, long double
	using r_string	=	std::string;	// preferring string over character will help semantics in a C++ domain
	using r_raw		=	char;			// or unint8_t?
	using r_date	=	std::tm;		// or time_t?

	using basic_data_types = std::variant<r_raw, r_integer, r_double, r_string, r_date>;

	enum ordinal_t { r_first = 1, r_second, r_third, r_fourth, r_fifth };

	/**
	 * @brief in R vectors can store any variable type.
	 * 
	 * @note unlike R variant_vectors are limited to the basic_data_types defined above
	 */
	using variant_vector = std::vector<basic_data_types>;

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

	/**
	 * .
	 */
	using data_frame_map = std::map<std::string, data_frame>;

	/**
	 * @brief (R-ish) as_dates convert between string representations and objects of type r_date representing 
	 * calendar dates.
	 */
	variant_vector as_dates(std::vector<std::string> dates);
	
	/**
	 * .
	 */
	token_t r_typeof(std::string& lexeme);

	/**
	 * .
	 */
	data_frame read_csv(std::string file_path, bool has_header = true);

	/**
	 * @brief (R-ish) sort (or order) a vector into ascending or descending order.
	 * 
	 * @param x				variant vector of values to sort
	 * @param decreasing	bool should the sort be increasing or decreasing?
	 */
	template<typename T>
	variant_vector sort (variant_vector& x, bool decreasing = false) {
		variant_vector y(x);
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) < std::get<T>(b);
		};
		if(decreasing) {
			std::sort(y.rbegin(), y.rend(), compare);
		}
		else {
			std::sort(y.begin(), y.end(), compare);
		}
		return y;
	}

	/**
	 * @brief (R-ish) sort (or order) a vector into ascending or descending order.
	 *
	 * @param x				variant vector of values to sort
	 * @param decreasing	bool should the sort be increasing or decreasing?
	 */
	template<typename T>
	variant_vector sort (variant_vector&& x, bool decreasing = false) {
		variant_vector y(x);
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) < std::get<T>(b);
		};
		if (decreasing) {
			std::sort(y.rbegin(), y.rend(), compare);
		}
		else {
			std::sort(y.begin(), y.end(), compare);
		}
		return y;
	}

	template<typename T>
	data_frame_map split(data_frame& x, variant_vector& v) {
		auto f = factor<T>(v);
	}

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 * 
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector& x) {
		// lambda equality functor that works with source variant type
		auto equals = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) == std::get<T>(b);
		};
		variant_vector r{ x };
		r.erase(std::unique(r.begin(), r.end(), equals), r.end());
		return r;
	}

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 *
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector&& x) {
		// lambda equality functor that works with source variant type
		auto equals = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) == std::get<T>(b);
		};
		variant_vector r{ x };
		r.erase(std::unique(r.begin(), r.end(), equals), r.end());
		return r;
	}

	/**
	 * @brief (R-ish) Range returns a pair containing the minimum and maximum of all the given argument
	 * 
	 * @param x		numeric vector of values to summarize
	 * @return		std::pair<double, double> min, max
	 */
	template<typename T> 
	std::pair<double, double> range(variant_vector& x) {
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) < std::get<T>(b);
		};
		std::pair<double, double> r;
		r.first = std::get<T>(*std::min_element(x.begin(), x.end(), compare));
		r.second = std::get<T>(*std::max_element(x.begin(), x.end(), compare));
		return r;
	}

	/**
	 * @brief (R-ish) Range returns a pair containing the minimum and maximum of all the given argument
	 *
	 * @param x		numeric vector of values to summarize
	 * @return		std::pair<double, double> min, max
	 */
	template<typename T>
	std::pair<double, double> range(variant_vector&& x) {
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) < std::get<T>(b);
		};
		std::pair<double, double> r;
		r.first = std::get<T>(*std::min_element(x.begin(), x.end(), compare));
		r.second = std::get<T>(*std::max_element(x.begin(), x.end(), compare));
		return r;
	}

	/**
	 * @brief (R-ish) Rescale numeric vector to have specified minimum and maximum.
	 *  
	 * Usage rescale(x, to = c(0, 1), from = range(x))
	 * 
	 * @param x		numeric vector of values to manipulate
	 * @param to	output range pair
	 * @param range	optional input range pair - if not given, is calculated from the range of x.
	 */
	template<typename T>
	void rescale(variant_vector& x, std::pair<double, double> to = std::pair(0.0, 1.0), std::pair<double, double> range = std::pair(0.0, 0.0) ) {
		if (range.first == range.second) {
			range = R::range<int>(x);
		}
		for (auto& i : x) {
			i = ((std::get<T>(i) - range.first) / (range.second - range.first)) * (to.second - to.first);
		}
	}

	/**
	 * @brief (R-ish) Floor converts numeric vector to largest integers not greater than the given numbers.
	 * 
	 * @param x		numeric vector of values to manipulate
	 */
	template<typename T = double>
	void floor(variant_vector& x) {
		for (auto& i : x) {
			i = std::floor(std::get<T>(i));
		}
	}
	

	template<typename T>	// x type and levels type must be the same
	variant_factor factor(variant_vector& x, variant_vector&& levels = {}, variant_vector&& labels = {}, variant_vector&& exclude = {}) {
		std::set<r_string> s;
		// if levels defined use it to build a unique categories vector otherwise build it from x
		variant_vector categories{ levels.size() ? R::unique<T>(levels) : R::unique<T>(x) };
		R::sort<T>(categories);		// sort categories
		variant_vector ordinals;	
	
		for (const auto& i : x) {		// check each x
			r_integer ordinal{ r_first };			
			for (const auto& c : categories) {	// against each category
				if (std::get<T>(c) == std::get<T>(i)) {
					ordinals.push_back(ordinal);
				}
				ordinal++;
			}
		}
	
		// read out all of the source levels using a string stream for conversion then insert into levels set
		/*
		for (const auto& i : source) {
			std::stringstream ss;
			r_string w;
			ss << std::get<U>(i);
			ss >> w;	// buggy sorts number as a string which numerically can be wrong order e.g. 200, 25
			s.insert(w);
		}
		*/
		// modify the x vector to categories 1st, 2nd, ... nth

		// return a string representation of the levels 
		//return y;//variant_vector{ s.begin(), s.end() };
		return variant_factor{ ordinals, categories };
	}

}

/*-------- stream operator overloads --------*/

std::ostream& operator<<(std::ostream& os, const R::r_date& date);

std::ostream& operator<<(std::ostream& os, const R::variant_vector& vv);

std::ostream& operator<<(std::ostream& os, const R::variant_factor& vf);

std::ostream& operator<<(std::ostream& os, const R::data_frame& df);