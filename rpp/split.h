#pragma once

#include "containers.h"

#include <map>
#include <string>

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
	variant_list<std::string, data_frame> split(data_frame& x, variant_vector& v) {
		variant_list<T, data_frame> tdf;
		auto f = factor<T>(v);			// define the groups by the factor levels
		for (const auto& level : f.second) {

		}
		return tdf;
	}

}