
#pragma once

#include "data_structures.h"

namespace R {

	/**
	* @brief (R-ish) Rescale numeric vector to have specified minimum and maximum.
	*
	* Usage rescale(x, to = c(0, 1), from = range(x))
	*
	* @tparam T		variant type
	* @param x		numeric vector of values to manipulate
	* @param to		output range pair
	* @param range	optional input range pair - if not given, is calculated from the range of x.
	* @return		variant_vector
	*/
	template<typename T>
	variant_vector rescale(variant_vector& x, std::pair<double, double> to = std::pair(0.0, 1.0), std::pair<double, double> range = std::pair(0.0, 0.0)) {
		variant_vector vv{ x };
		if (range.first == range.second) {
			range = R::range<int>(x);
		}
		for (auto& i : vv) {
			i = to.first + (((std::get<T>(i) - range.first) / (range.second - range.first)) * (to.second - to.first));
		}
		return vv;
	}

	/**
	* @brief (R-ish) Rescale numeric vector to have specified minimum and maximum.
	*
	* Usage rescale(x, to = c(0, 1), from = range(x))
	*
	* @tparam T		variant type
	* @param x		numeric vector of values to manipulate
	* @param to		output range pair
	* @param range	optional input range pair - if not given, is calculated from the range of x.
	* @return		variant_vector
	*/
	template<typename T>
	variant_vector rescale(variant_vector&& x, std::pair<double, double> to = std::pair(0.0, 1.0), std::pair<double, double> range = std::pair(0.0, 0.0)) {
		variant_vector vv{ x };
		if (range.first == range.second) {
			range = R::range<int>(x);
		}
		for (auto& i : vv) {
			i = to.first + (((std::get<T>(i) - range.first) / (range.second - range.first)) * (to.second - to.first));
		}
		return vv;
	}

}
