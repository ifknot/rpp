#pragma once

#include "types.h"

#include <algorithm>

namespace R {

	template<typename T>
	std::vector<r_integer> match(variant_vector& x, variant_vector& table) {
		std::vector<r_integer> v;
		for (const auto& a : table) {
			auto it = std::find_if(
				x.begin(), 
				x.end(), 
				[&](const basic_data_types& b) { 
					return std::get<T>(a) == std::get<T>(b); 
				}
			);
			if (it != x.end()) {
				v.push_back(static_cast<r_integer>(distance(x.begin(), it)));
			}
		}
		return v;
	}

	template<typename T>
	std::vector<r_integer> match(variant_vector&& x, variant_vector&& table) {
		std::vector<r_integer> v;
		for (const auto& a : table) {
			auto it = std::find_if(
				x.begin(),
				x.end(),
				[&](const basic_data_types& b) { 
					return std::get<T>(a) == std::get<T>(b); 
				}
			);
			if (it != x.end()) {
				v.push_back(static_cast<r_integer>(distance(x.begin(), it)));
			}
		}
		return v;
	}

}