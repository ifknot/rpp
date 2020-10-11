#pragma once

#include <math.h>
#include <unordered_set>

#include "data_structures.h"

namespace R {

	// TODO: comparators for numeric(because f.p.), date, and complex
	// auto cmp = [](int a, int b) { return ... };
	// std::set<int, decltype(cmp)> s(cmp);

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 * @note maintains the original order of the remaining elements.
	 *
	 * @tparam T	variant type
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector& x) {
		if (x.size() == 0 || x.size() == 1) {
			return x;
		}
		std::vector<T> vv;
		for (const auto& v : x) {
			vv.push_back(std::get<T>(v));
		}
		std::set<T> s(vv.begin(), vv.end());
		vv.assign(s.begin(), s.end());
		return variant_vector{};
	}

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 *
	 * @tparam T	variant type
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector&& x) {
		
		return variant_vector{};
	}

}