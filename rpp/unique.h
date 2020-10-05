#pragma once

#include <math.h>
#include <unordered_set>

#include "data_structures.h"

namespace R {

	// TODO: comparators for numeric(because f.p.), date, and complex
	// auto cmp = [](int a, int b) { return ... };
	// std::set<int, decltype(cmp)> s(cmp);

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 *
	 * @tparam T	variant type
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector& x) {
		if (x.size() == 0 || x.size() == 1) {
			return x;
		}
		std::unordered_set<T> s;
		for (const auto& v : x) {
			s.emplace(std::get<T>(v));
		}
		variant_vector v(s.begin(), s.end());
		return v;
	}

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 *
	 * @tparam T	variant type
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector&& x) {
		if (x.size() == 0 || x.size() == 1) {
			return x;
		}
		std::unordered_set<T> s;
		for (const auto& v : x) {
			s.emplace(std::get<T>(v));
		}
		variant_vector v(s.begin(), s.end());
		return v;
	}

}

/*

switch (x[0].index()) {
	case _num:
	{	// lambda equality function for fp values as per "The art of computer programming" by Knuth
		auto almost_equals = [&](const r_type& aa, const r_type& bb) {
			std::cout << aa.index() << ',' << bb.index() <<std::endl;
			assert(aa.index() == _num && bb.index() == _num);
			auto a{ std::get<r_numeric>(aa) };
			auto b{ std::get<r_numeric>(bb) };
			auto epsilon = std::numeric_limits<double>::epsilon();
			return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
		};
		variant_vector v{ x };
		v.erase(std::unique(v.begin(), v.end(), almost_equals), v.end());
		return v;
	}
	default:
	{	// lambda equality functor that works with non-fp variant type
		auto equals = [&](const r_type& a, const r_type& b) {
			assert(a.index() == b.index());
			return std::get<T>(a) == std::get<T>(b);
		};
		variant_vector v{ x };
		v.erase(std::unique(v.begin(), v.end(), equals), v.end());
		return v;
	}
}

*/