#pragma once

#include "containers.h"

namespace R {


	/**
	 * Returns the first n items of a variant vector
	 */
	variant_vector head(const variant_vector& x, int n = 6);

	/**
	 * Returns the first n rows of a data frame 
	 */
	data_frame head(const data_frame& x, int n = 6);

}