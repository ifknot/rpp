#pragma once

#include <vector>

#include "data_types.h"

namespace R {

	/**
	 * @brief in R vectors can store multiple variables of any *single* type i.e. they are type homogeneous
	 * to use R-lang parlance they are 'atomic' (which sounds odd to the C++ ear).
	 *
	 * R-ish vectors can be created using list initialization (curly braces), copy or =
	 *
	 * @note variant vectors *do not* check for type homogeneity.
	 * @note variant_vectors elements are limited to the variants defined in r_types
	 * @note unlike R, it is not possible to add names as indices
	 */
	using variant_vector = std::vector<r_type>;

}

std::ostream& operator << (std::ostream& os, const R::variant_vector& vv);