#pragma once

#include "containers.h"

namespace R {


	/**
	 * Returns the last n items of a variant vector
	 */
	variant_vector tail(const variant_vector& x, int n = 6);

	/**
	 * Returns the last n rows of a data frame
	 */
	data_frame tail(const data_frame& x, int n = 6);

}