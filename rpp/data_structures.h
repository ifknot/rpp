#pragma once

#include "data_types.h"

#include <vector>
#include <unordered_map>

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
	 * @brief in R a list can store multiple variables of multiple types i.e. they are type heterogeneous 
	 * 
	 * R-ish vectors can be created using list initialization (curly braces), copy or =
	 *
	 * @note from a design perspective rather using r_type variant as the index, permit wider range of types T
	 */
	template<typename T, typename U>
	using variant_list = std::unordered_map<T, U>;

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
	using data_frame = std::unordered_map<std::string, variant_vector>;

}