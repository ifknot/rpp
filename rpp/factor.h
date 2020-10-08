#pragma once

#include "data_structures.h"
#include "sort.h"

namespace R {

	/**
	 * @brief (R-ish) factor - convert variant vector type T into a std::pair of vectors:
	 * 1. vector of integer categories original length
	 * 2. vector of T unique levels 
	 * @note this a departure from R as the original type of the levels is preserved (better?)
	 * @note if the original behaviour is desired use std::to_string on the basic type or << and a std::stringstream
	 * 
	 * @tparam T			variant type
	 * @param x				a vector of data, usually taking a small number of distinct values
	 * @param levels		
	 * @param labels
	 * @param exclude
	 * @return				variant_factor (pair as vector of integer categories original length and a unique vector of levels type T)  
	 */
	template<typename T>	// x type and levels type must be the same
	variant_factor factor(variant_vector& x, variant_vector&& levels = {}, variant_vector&& labels = {}, variant_vector&& exclude = {}) {
		// if levels defined use it to build a unique categories vector otherwise build it from x
		variant_vector categories{ levels.size() ? R::sort<T>(R::unique<T>(levels)) : R::sort<T>(R::unique<T>(x)) };
		// TODO: as_string
		variant_vector ordinals;
		for (const auto& i : x) {		// check each x
			r_integer ordinal{ first };
			for (const auto& c : categories) {	// against each category
				if (std::get<T>(c) == std::get<T>(i)) {
					ordinals.push_back(ordinal);
				}
				ordinal++;
			}
		}

		return variant_factor{ ordinals, categories };
	}

	template<typename T>	// x type and levels type must be the same
	variant_factor factor(variant_vector&& x, variant_vector&& levels = {}, variant_vector&& labels = {}, variant_vector&& exclude = {}) {
		// if levels defined use it to build a unique categories vector otherwise build it from x
		variant_vector categories{ levels.size() ? R::sort<T>(R::unique<T>(levels)) : R::sort<T>(R::unique<T>(x)) };
		// TDOD: aa_string
		variant_vector ordinals;
		std::cout << "{" << categories << "}\n";
		for (const auto& i : x) {		// check each x
			r_integer ordinal{ first };
			for (const auto& c : categories) {	// against each category
				if (std::get<T>(c) == std::get<T>(i)) {
					ordinals.push_back(ordinal);
				}
				ordinal++;
			}
		}

		return variant_factor{ ordinals, categories };
	}

}
