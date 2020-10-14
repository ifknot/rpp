
#pragma once

#include <unordered_map>

#include "data_types.h"
#include "variant_vector.h"

namespace R {

	/**
	 * @brief As per R language definition the following are the characteristics of an R-ish data frame:
	 *
	 * + The column names should be non-empty.
	 * + The row names should be unique.
	 * + The data stored in a data frame can be of an r-type.
	 * + Each column should contain same number of data items.
	 *
	 * @note *none* of these characteristics are checked for.
	 */
	using data_frame = std::unordered_map<r_string, variant_vector>;

}

std::ostream& operator << (std::ostream& os, const R::data_frame& df);

