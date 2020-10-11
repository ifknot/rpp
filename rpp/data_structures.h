#pragma once

#include "string_vector.h"
#include "ordinal_vector.h"
#include "variant_vector.h"
#include "variant_factor.h"

#include <vector>
#include <unordered_map>

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

	// TODO: typename T
	using data_frame_list = std::unordered_map<r_string, data_frame>;

}