#pragma once

#include "types.h"

#include <vector>
#include <unordered_map>

namespace R {

	/**
	 * @brief in R vectors can store any variable type.
	 *
	 * @note unlike R, variant_vectors are limited to the data_variants defined above
	 */
	using variant_vector = std::vector<r_type>;

	/**
	 * @brief In R factors are data objects used to categorize data and store it as levels.
	 *
	 * Stored as a pair of integer and string variant vectors they can be used to convert unique values into
	 * ordinal integers.
	 * @note unlike R factors can not be stored in a data_frame but either of the pairs variant vectors can be.
	 * The first variant_vector of the pair is the ordinal integers, the second is the levels.
	 */
	using variant_factor = std::pair<variant_vector, variant_vector>;

	/**
	 * As per R language definition the following are the characteristics of a data frame
	 *
	 * - The column names should be non-empty.
	 * - The row names should be unique.
	 * - The data stored in a data frame can be of numeric, factor or character type.
	 * - Each column should contain same number of data items.
	 */
	using data_frame = std::unordered_map<std::string, variant_vector>;

}