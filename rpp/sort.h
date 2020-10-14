
#pragma once

#include "data_structures.h"

#include <algorithm>

namespace R {

	/**
	 * @brief (R-ish) sort (or order) a vector into ascending or descending order.
	 *
	 * @tparam T			variant type
	 * @param x				variant vector of values to sort
	 * @param decreasing	bool should the sort be increasing or decreasing?
	 * @return				sorted variant_vector
	 */
	template<typename T>
	variant_vector sort (variant_vector& x, bool decreasing = false) {
		variant_vector vv{ x };
		// lambda compare functor that works with source variant type 
		auto compare = [&](const r_type& a, const r_type& b) {
			return (decreasing) ? std::get<T>(b) < std::get<T>(a) : std::get<T>(a) < std::get<T>(b);
		};
		std::sort(vv.begin(), vv.end(), compare);
		return vv;
	}

	/**
	 * @brief (R-ish) sort (or order) a vector into ascending or descending order.
	 *
	 * @tparam T			variant type
	 * @param x				variant vector of values to sort
	 * @param decreasing	bool should the sort be increasing or decreasing?
	 * @return				sorted variant_vector
	 */
	template<typename T>
	variant_vector sort (variant_vector&& x, bool decreasing = false) {
		variant_vector vv{ x };
		// lambda compare functor that works with source variant type 
		auto compare = [&](const r_type& a, const r_type& b) {
			return (decreasing) ? std::get<T>(a) < std::get<T>(b) : std::get<T>(b) < std::get<T>(a);
		};	
		std::sort(vv.begin(), vv.end(), compare);
		return vv;
	}

}