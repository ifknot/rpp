
#pragma once

#include "data_structures.h"
#include "sort.h"
#include "as_string.h"

namespace R {

	/**
	 * @brief (R-ish) factor - convert variant vector type T into a variant factor:
	 * 1. vector of r_ordinal categories original length
	 * 2. vector of r_string unique levels 
	 * 
	 * @tparam T			variant type
	 * @param x				a vector of data, usually taking a small number of distinct values
	 * @param levels		
	 * TODO: param labels
	 * TODO: param exclude
	 * @return				variant_factor (pair as vector of r_ordinal categories original length and a unique vector of r_string levels)  
	 */
	template<typename T>
	variant_factor factor(variant_vector& x, variant_vector&& levels = {}, variant_vector&& labels = {}, variant_vector&& exclude = {}) {
		// if levels defined use it to build a unique categories string vector otherwise build it from x
		auto categories{ levels.size()
			? R::unique<T>(R::sort<T>(levels))
			: R::unique<T>(R::sort<T>(x))
		};
		ordinal_vector ordinals;
		for (const auto& v : x) {		// check each x
			r_integer rank{ first };
			for (const auto& c : categories) {	// against each category
				if (std::get<T>(c) == std::get<T>(v)) {
					ordinals.push_back(rank);
				}
				rank++;
			}
		}
		return std::make_pair(ordinals, as_string(categories));
	}

	/**
	 * @brief (R-ish) factor - convert variant vector type T into a variant factor:
	 * 1. vector of r_ordinal categories original length
	 * 2. vector of r_string unique levels
	 *
	 * @tparam T			variant type
	 * @param x				a vector of data, usually taking a small number of distinct values
	 * @param levels
	 * TODO: param labels
	 * TODO: param exclude
	 * @return				variant_factor (pair as vector of r_ordinal categories original length and a unique vector of r_string levels)
	 */
	template<typename T>
	variant_factor factor(variant_vector&& x, variant_vector&& levels = {}, variant_vector&& labels = {}, variant_vector&& exclude = {}) {
		// if levels defined use it to build a unique categories string vector otherwise build it from x
		auto categories{ levels.size()
			? R::unique<T>(R::sort<T>(levels))
			: R::unique<T>(R::sort<T>(x))
		};
		ordinal_vector ordinals;
		for (const auto& v : x) {		// check each x
			r_integer rank{ first };
			for (const auto& c : categories) {	// against each category
				if (std::get<T>(c) == std::get<T>(v)) {
					ordinals.push_back(rank);
				}
				rank++;
			}
		}
		return std::make_pair(ordinals, as_string(categories));
	}

}
