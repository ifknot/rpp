
#pragma once

#include "data_structures.h"

namespace R {

	/**
	 * @brief (R-ish) matchAll (from the tupple-package)
	 * Returns an integer vector of the index in table for all the matches.
	 * The result is not sorted in numerical index order when more than one value is sought to be matched.
	 * Instead, the matches of the first value in x are listed first, followed by matches to the second value in x and so on.
	 * @note NA = -1
	 *
	 * @tparam T		variant type
	 * @param x			vector of values to be matched.
	 * @param table		vector of values to be matched against.
	 * @return			variant_vector of r_integer indices where matches occur
	 */
	template< typename T>
	variant_vector match_all(variant_vector& x, variant_vector& table) {
		variant_vector vv;
		for (const auto& a : table) {
			auto i = x.begin();
			auto n = vv.size();
			while ((i = std::find_if(i, x.end(),
				[&](const r_type& b) {
					return std::get<T>(a) == std::get<T>(b);
				}
			)) != x.end()) {
				vv.push_back(static_cast<r_integer>(distance(x.begin(), i)));
				i++;
			}
			if (n == vv.size()) {
				vv.push_back(NA);
			}
		}
		return vv;
	}

	/**
	 * @brief (R-ish) matchAll (from the tupple-package)
	 * Returns an integer vector of the index in table for all the matches. 
	 * The result is not sorted in numerical index order when more than one value is sought to be matched. 
	 * Instead, the matches of the first value in x are listed first, followed by matches to the second value in x and so on. 
	 * @note NA = -1
	 *
	 * @tparam T		variant type
	 * @param x			vector of values to be matched.
	 * @param table		vector of values to be matched against.
	 * @return			variant_vector of r_integer indices where matches occur
	 */
	template< typename T>
	variant_vector match_all(variant_vector& x, variant_vector&& table) {
		variant_vector vv;
		for (const auto& a : table) {
			auto i = x.begin();
			auto n = vv.size();
			while ((i = std::find_if(i, x.end(), 
				[&](const r_type& b) {
					return std::get<T>(a) == std::get<T>(b);
				}
				)) != x.end()) {
				vv.push_back(static_cast<r_integer>(distance(x.begin(), i)));
				i++;
			}
			if (n == vv.size()) {
				vv.push_back(NA);
			}
		}
		return vv;
	}
	/**
	 * @brief (R-ish) matchAll (from the tupple-package)
	 * Returns an integer vector of the index in table for all the matches.
	 * The result is not sorted in numerical index order when more than one value is sought to be matched.
	 * Instead, the matches of the first value in x are listed first, followed by matches to the second value in x and so on.
	 * @note NA = -1
	 *
	 * @tparam T		variant type
	 * @param x			vector of values to be matched.
	 * @param table		vector of values to be matched against.
	 * @return			variant_vector of r_integer indices where matches occur
	 */
	template< typename T>
	variant_vector match_all(variant_vector&& x, variant_vector&& table) {
		variant_vector vv;
		for (const auto& a : table) {
			auto i = x.begin();
			auto n = vv.size();
			while ((i = std::find_if(i, x.end(),
				[&](const r_type& b) {
					return std::get<T>(a) == std::get<T>(b);
				}
			)) != x.end()) {
				vv.push_back(static_cast<r_integer>(distance(x.begin(), i)));
				i++;
			}
			if (n == vv.size()) {
				vv.push_back(NA);
			}
		}
		return vv;
	}

}

