#pragma once

#include "types.h"

#include <vector>
#include <unordered_map>

namespace R {

	/**
	 * @brief in R vectors can store any variable type.
	 *
	 * @note variant_vectors elements are limited to the variants defined in r_types
	 * @note unlike R, it is not possible to add names to indices
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
	 * @brief in R a list is a generic vector containing r_types or other containers
	 *
	 * @note from a design perspective rather using r_type variant as the index, a permit wider range of types T
	 */
	template<typename T, typename U>
	using variant_list = std::unordered_map<T, U>;

	/**
	 * @brief As per R language definition the following are the characteristics of a data frame
	 *
	 * - The column names should be non-empty.
	 * - The row names should be unique.
	 * - The data stored in a data frame can be of numeric, factor or character type.
	 * - Each column should contain same number of data items.
	 */
	using data_frame = std::unordered_map<std::string, variant_vector>;

}