#pragma once

#include "types.h"

namespace R {

	template<typename T>	// x type and levels type must be the same
	variant_factor factor(variant_vector& x, variant_vector&& levels = {}, variant_vector&& labels = {}, variant_vector&& exclude = {}) {
		// if levels defined use it to build a unique categories vector otherwise build it from x
		variant_vector categories{ levels.size() ? R::unique<T>(levels) : R::unique<T>(x) };
		R::sort<T>(categories);		// sort categories
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
		variant_vector categories{ levels.size() ? R::unique<T>(levels) : R::unique<T>(x) };
		R::sort<T>(categories);		// sort categories
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

}
