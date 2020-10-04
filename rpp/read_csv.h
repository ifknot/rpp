#pragma once

#include "data_structures.h"

namespace R {

	data_frame read_csv(std::string file_path, bool has_header = true);

}