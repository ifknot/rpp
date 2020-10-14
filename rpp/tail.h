
#pragma once

#include "data_structures.h"

namespace R {


	/**
	 * Returns the last n items of a variant vector
	 */
	variant_vector tail(const variant_vector& x, size_t n = 6);

	/**
	 * Returns the last n rows of a data frame
	 */
	data_frame tail(const data_frame& x, size_t n = 6);

}