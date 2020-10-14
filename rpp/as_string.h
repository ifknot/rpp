
#pragma once

#include "data_structures.h"

namespace R {

	std::string as_string(const r_type& x);

	std::string as_string(const r_type&& x);

	/**
	 * @brief attempts to coerce its argument variant vector to variant vector of r_string
	 */
	string_vector as_string(const variant_vector& x);

	/**
	 * @brief attempts to coerce its argument variant vector to variant vector of r_string
	 */
	string_vector as_string(const variant_vector&& x);

}