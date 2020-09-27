#include "types.h"

#include <algorithm>

namespace R {

	/**
	 * @brief (R-ish) sort (or order) a vector into ascending or descending order.
	 *
	 * @param x				variant vector of values to sort
	 * @param decreasing	bool should the sort be increasing or decreasing?
	 * @return				variant_vector
	 */
	template<typename T>
	variant_vector sort (variant_vector& x, bool decreasing = false) {
		variant_vector v{ x };
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) > std::get<T>(b);
		};
		if (decreasing) {
			std::sort(v.rbegin(), v.rend(), compare);
		}
		else {
			std::sort(v.begin(), v.end(), compare);
		}
		return v;
	}

	/**
	 * @brief (R-ish) sort (or order) a vector into ascending or descending order.
	 *
	 * @param x				variant vector of values to sort
	 * @param decreasing	bool should the sort be increasing or decreasing?
	 * @return				variant_vector
	 */
	template<typename T>
	variant_vector sort (variant_vector&& x, bool decreasing = false) {
		variant_vector v{ x };
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) < std::get<T>(b);
		};
		if (decreasing) {
			std::sort(v.rbegin(), v.rend(), compare);
		}
		else {
			std::sort(v.begin(), v.end(), compare);
		}
		return v;
	}

}