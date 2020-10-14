
#pragma once

#include <math.h>

#include "data_structures.h"

namespace R {

	/**
	 * @brief (R-ish) Floor converts numeric vector to largest integers not greater than the given numbers.
	 *
	 * @tparam T	variant type
	 * @param x		numeric vector of values to manipulate
	 * @return		variant_vector
	 */
	template<typename T = double>
	variant_vector floor(variant_vector& x) {
		variant_vector vv{ x };
		for (auto& i : vv) {
			i = std::floor(std::get<T>(i));
		}
		return vv;
	}

	/**
	 * @brief (R-ish) Floor converts numeric vector to largest integers not greater than the given numbers.
	 *
	 * @tparam T	variant type
	 * @param x		numeric vector of values to manipulate
	 * @return		variant_vector
	 */
	template<typename T = double>
	variant_vector floor(variant_vector&& x) {
		variant_vector vv{ x };
		for (auto& i : vv) {
			i = std::floor(std::get<T>(i));
		}
		return vv;
	}

}