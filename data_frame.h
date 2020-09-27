#pragma once


#include "R.h"

namespace R {

	/**
	 * .
	 *
	 * @tparam T
	 * @param x
	 * @param v
	 * @return
	 */
	template<typename T>
	std::map<T, data_frame> split(data_frame& x, variant_vector& v) {
		auto f = factor<T>(v);
		return std::map<T, data_frame>;
	}

}
