#pragma once

#include "data_structures.h"

#include <algorithm>

namespace R {

	/**
	 * @brief (R-ish) match returns a vector of the positions of *first* matches of its first argument in its second.
	 * @note NA = -1
	 *
	 * @tparam T		variant type
	 * @param x			vector of values to be matched.
	 * @param table		vector of values to be matched against.
	 * @return			variant_vector of r_integer indices where matches occur
	 *
	 * @todo	nomatch
	 * @todo	incomparables
	 */
	template<typename T>
	variant_vector match(variant_vector& x, variant_vector& table) {
		variant_vector v;
		for (const auto& a : table) {
			auto it = std::find_if(
				x.begin(),
				x.end(),
				[&](const r_type& b) {
					return std::get<T>(a) == std::get<T>(b);
				}
			);
			if (it != x.end()) {
				v.push_back(static_cast<r_integer>(distance(x.begin(), it)));
			}
			else {
				v.push_back(NA);
			}
		}
		return v;
	}

	/**
	 * @brief (R-ish) match returns a vector of the positions of *first* matches of its first argument in its second.
	 * @note NA = -1
	 * 
	 * @tparam T		variant type
	 * @param x			vector of values to be matched.
	 * @param table		vector of values to be matched against.
	 * @return			variant_vector of r_integer indices where matches occur
	 * 
	 * @todo	nomatch
	 * @todo	incomparables
	 */
	template<typename T>
	variant_vector match(variant_vector& x, variant_vector&& table) {
		variant_vector v;
		for (const auto& a : table) {
			auto it = std::find_if(
				x.begin(), 
				x.end(), 
				[&](const r_type& b) { 
					return std::get<T>(a) == std::get<T>(b); 
				}
			);
			if (it != x.end()) {
				v.push_back(static_cast<r_integer>(distance(x.begin(), it)));
			}
			else {
				v.push_back(NA);
			}
		}
		return v;
	}

	/**
	 * @brief (R-ish) match returns a vector of the positions of (first) matches of its first argument in its second.
	 * @note NA = -1
	 *
	 * @tparam T		variant type
	 * @param x			vector of values to be matched.
	 * @param table		vector of values to be matched against.
	 * @return			variant_vector of r_integer indices where matches occur
	 * 
	 * @todo	nomatch
	 * @todo	incomparables
	 */
	template<typename T>
	variant_vector match(variant_vector&& x, variant_vector&& table) {
		variant_vector v;
		for (const auto& a : table) {
			auto it = std::find_if(
				x.begin(),
				x.end(),
				[&](const r_type& b) { 
					return std::get<T>(a) == std::get<T>(b); 
				}
			);
			if (it != x.end()) {
				v.push_back(static_cast<r_integer>(distance(x.begin(), it)));
			}
			else {
				v.push_back(NA);
			}
		}
		return v;
	}

}