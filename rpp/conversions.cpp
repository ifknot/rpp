#include "conversions.h"

#include <iomanip>
#include <sstream>

namespace R {

	std::tm string_to_tm(const std::string str, bool is_dst, const std::string format) {
		std::tm tm;
		std::istringstream ss;
		ss >> std::get_time(&tm, format.c_str());
		return tm;
	}

}

/*
for (const auto& date : dates) {
	std::stringstream ss;
	ss << date + "T00:00:00Z ";
std:tm tm;
	ss >> std::get_time(&tm, "%Y-%m-%d");// T% H:% M : % S");
	auto time = mktime(&tm);
	tm_dates.push_back(tm);
}
*/

