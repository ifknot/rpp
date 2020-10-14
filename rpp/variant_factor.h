
#pragma once

#include <vector>

#include "data_types.h"
#include "ordinal_vector.h"
#include "string_vector.h"

namespace R {

	/**
	 * @brief In R factors are data objects used to categorize data and store it as levels.
	 *
	 * Stored as a pair of unsigned integer and string vectors they can be used to convert unique values into
	 * ordinal integers.
	 * @note unlike R factors can not be stored in a data_frame but either of the pairs variant vectors can be.
	 * The first variant_vector of the pair is the ordinal integers, the second is the levels.
	 */
	using variant_factor = std::pair<ordinal_vector, string_vector>;

}

std::ostream& operator<<(std::ostream& os, const R::variant_factor& vf);
