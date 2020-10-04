#pragma once

#include <ctime>
#include <string>

namespace R {

	std::tm string_to_tm(const std::string str, bool is_dst = false, const std::string format = "%Y-%m-%d %H:%M:%S");	

}
