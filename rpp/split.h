#pragma once

#include "data_structures.h"

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
	variant_list<T, data_frame> split(data_frame& x, variant_vector& v) {
		//variant_list<T, data_frame> tdf;
		//auto f = factor<T>(v);			// define the groups by the factor levels
		//for (const auto& level : f.second) {
			//std::count << " " << level;
		//}
		return variant_list<T, data_frame>;// tdf;
	}

	//variant_list<std::string, data_frame> split(data_frame& x, variant_factor& f)

	//variant_list<std::string, data_frame> split(variant_vector& x, variant_vector& f& v)

	//variant_list<std::string, data_frame> split(variant_vector& x, variant_factor& f)


}