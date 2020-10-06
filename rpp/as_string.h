#pragma once

#include "data_structures.h"

namespace R {

	/**
	 * @brief attempts to coerce its argument variant vector to variant vector of r_string
	 */
	variant_vector as_string(const variant_vector& x);

}