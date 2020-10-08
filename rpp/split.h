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
	data_frame_list split(data_frame& x, variant_vector& v) {
		data_frame_list split_list;
		auto [ordinals, levels] = R::factor<T>(v);			// define the groups by the factor levels

		auto i = 1u;
		for (const auto& level : levels) {
			std::cout << "$" << std::get<r_string>(level) << '\n';
			//data_frame df;
			for (const auto& [key, vec] : x) {
				//if(ordinals[j] = )
				std::cout << key;
				auto j = 0u;
				for (const auto& v : vec) {
					std::cout << ' ' << std::get<r_integer>(ordinals[j++]) << ',' << i;
				}
				std::cout << '\n';
			}

			//split_list[level] = df;
			++i;
			std::cout << '\n';


		}
		//each level as the key
			//temp df
			//for x key, vec
			// new df to each level as key
			// step through each ordinal if it matches the current level then add to df each key from source df to build a row
			//build a vv of enumerate rows as per the ordinals
		return split_list;
	}

}