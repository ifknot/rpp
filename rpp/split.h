
#pragma once

#include "data_structures.h"
#include "factor.h"
#include "as_string.h"

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
	 list<data_frame> split(data_frame& x, variant_vector& v) {
		list<data_frame> split_list;
		const auto& [ordinal, levels] = factor<T>(v);			// define the groups by the factor levels
		for (int rank{ first }; const auto & level : levels) {	// for each of the levels 
			for (const auto& [key, vec] : x) {					// for each column in the source data frame
				for (auto row{ 0u }; const auto & v : vec) {	// for each row in that column
					if (ordinal[row++] == rank) {				// check the factor's ordinals against the current rank
						split_list[level][key].push_back(v);    // copy that row of that column to the level data frame
					}
				}
			}							
			++rank;
		}
		return split_list;
	}

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
	list<data_frame> split(data_frame& x, variant_vector&& v) {
		list<data_frame> split_list;
		const auto& [ordinal, levels] = factor<T>(v);			// define the groups by the factor levels
		for (int rank{ first }; const auto & level : levels) {	// for each of the levels 
			for (const auto& [key, vec] : x) {					// for each column in the source data frame
				for (auto row{ 0u }; const auto & v : vec) {	// for each row in that column
					if (ordinal[row++] == rank) {				// check the factor's ordinals against the current rank
						split_list[level][key].push_back(v);    // copy that row of that column to the level data frame
					}
				}
			}
			++rank;
		}
		return split_list;
	}

}