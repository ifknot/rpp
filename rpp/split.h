#pragma once

#include "data_structures.h"
#include "factor.h"

#include <map>
#include <string>

namespace R {

	/**
	 * @ brief Divide into groups.
	 * split divides the data in the data frame x into the groups defined by vector f.  
	 * @note unsplit reverses the effect of split.
	 *
	 * @tparam T	variant type
	 * @param x		data frame containing values to be divided into groups
	 * @param f		a ‘factor’ in the sense that factor(f) defines the grouping
	 * @return		list of data frames containing the values for the groups, named by the levels of f (after converting to a factor)
	 */
	template<typename T>
	variant_list split(data_frame& x, variant_vector& v) {
		variant_list vl;
		auto f = R::factor<T>(v);			// define the groups by the factor levels
		auto& levels = f.second;
		for (const auto& l : levels) {
			std::cout << " " << std::get<T>(l);
		}
		return vl;
	}




}