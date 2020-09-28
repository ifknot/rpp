#pragma once

#include "types.h"

#include <map>

namespace R {

	/**
	 * .
	 *
	 * @tparam T	variant type
	 * @param x
	 * @param v
	 * @return
	 */
	template<typename T>
	std::map<T, data_frame> split(data_frame& x, variant_vector& v) {
		auto f = factor<T>(v);			// define the groups by the factor levels

		return std::map<T, data_frame>;
	}

}