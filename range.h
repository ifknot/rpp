#pragma once

#include "types.h"

#include <utility>


namespace R {

	/**
	 * @brief (R-ish) Range returns a pair containing the minimum and maximum of all the given argument
	 *
	 * @param x		numeric vector of values to summarize
	 * @return		std::pair<double, double> min, max
	 */
	template<typename T>
	std::pair<T, T> range(variant_vector& x) {
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(b) > std::get<T>(a);
		};
		std::pair<double, double> p;
		p.first = std::get<T>(*std::min_element(x.begin(), x.end(), compare));
		p.second = std::get<T>(*std::max_element(x.begin(), x.end(), compare));
		return p;
	}

	/**
	 * @brief (R-ish) Range returns a pair containing the minimum and maximum of all the given argument
	 *
	 * @param x		numeric vector of values to summarize
	 * @return		std::pair<double, double> min, max
	 */
	template<typename T>
	std::pair<T, T> range(variant_vector&& x) {
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(b) > std::get<T>(a);
		};
		std::pair<double, double> p;
		p.first = std::get<T>(*std::min_element(x.begin(), x.end(), compare));
		p.second = std::get<T>(*std::max_element(x.begin(), x.end(), compare));
		return p;
	}

}