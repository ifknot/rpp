
#pragma once

#include "data_structures.h"

namespace R {


	/**
	 * Returns the first n items of a variant vector
	 */
	variant_vector head(const variant_vector& x, size_t n = 6);

	/**
	 * Returns the first n rows of a data frame 
	 */
	data_frame head(const data_frame& x, size_t n = 6);

}