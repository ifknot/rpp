
#pragma once

#include <algorithm>

#include "data_structures.h"
#include "sort.h"

namespace R {

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 * @note preserves the original order but at the price of O(n)
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
		variant_vector vv;
		for (const auto& a : x) {
			if (!std::any_of(vv.begin(), vv.end(), [&](const r_type& b) {
				return std::get<T>(a) == std::get<T>(b);
				})) {
				vv.push_back(a);
			}
		}
		return vv;
	}

	/**
	 * @brief (R-ish) unique returns a sorted variant vector like x but with duplicate elements removed.
	 * @note preserves the original order but at the price of O(n)
	 * 
	 * @tparam T	variant type
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector&& x) {
		if (x.size() == 0 || x.size() == 1) {
			return x;
		}
		variant_vector vv;
		for (const auto& a : x) {
			if (!std::any_of(vv.begin(), vv.end(), [&](const r_type& b) {
				return std::get<T>(a) == std::get<T>(b);
			})) {
				vv.push_back(a);
			}
		}
		return vv;
	}

}

/*

if (x.size() == 0 || x.size() == 1) {
			return x;
		}
		variant_vector vv = sort<T>(x);
		auto equals = [&](const r_type& a, const r_type& b) {
			return std::get<T>(a) == std::get<T>(b);
		};
		vv.erase(std::unique(vv.begin(), vv.end(), equals), vv.end());
		return vv;

*/