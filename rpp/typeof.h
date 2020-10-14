
#pragma once

#include "data_types.h"
#include "variant_vector.h"
#include <string>

namespace R {

	inline std::string typeof(r_type x) {
		return index_to_string[x.index()];
	}

	std::string typeof(variant_vector x);

}
