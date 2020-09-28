#pragma once

#include "types.h"

#include <math.h>

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
		variant_vector v{ x };
		for (auto& i : v) {
			i = std::floor(std::get<T>(i));
		}
		return v;
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
		variant_vector v{ x };
		for (auto& i : v) {
			i = std::floor(std::get<T>(i));
		}
		return v;
	}

}