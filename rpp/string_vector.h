
#pragma once

#include <vector>

#include "data_types.h"

namespace R {

	using string_vector = std::vector<r_string>;

}

std::ostream& operator<<(std::ostream& os, const R::string_vector& sv);
