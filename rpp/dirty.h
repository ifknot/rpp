
#pragma once

#include "data_structures.h"

namespace R {

	/**
	 * @brief check if a variant vector is technically correct i.e. all same type
	 *
	 * @tparam T			variant type
	 * @param x				variant vector of values to check
	 * @return				variant_vector of indices of non-matching types
	 */
	template<r_index T>
	variant_vector dirty(variant_vector x) {
		variant_vector vv;
		for (size_t i{ 0 }; i < x.size(); ++i) {
			if (x[i].index() != T) {
				vv.push_back(static_cast<r_integer>(i));
			}
		}
		return vv;
	}

}
