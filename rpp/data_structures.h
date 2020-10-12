#pragma once

#include "string_vector.h"
#include "ordinal_vector.h"
#include "variant_vector.h"
#include "variant_factor.h"
#include "data_frame.h"

#include <unordered_map>

namespace R {	

	// TODO: typename T
	using data_frame_list = std::unordered_map<r_string, data_frame>;

	template<typename T>
	using list = std::unordered_map<r_string, T>;

}