
#pragma once

#include <vector>

#include "data_types.h"

namespace R {

	using ordinal_vector = std::vector<r_ordinal>;

}

std::ostream& operator<<(std::ostream& os, const R::ordinal_vector& ov);