#include "as_dates.h"

#include <iomanip>
#include <sstream>

namespace R {

	variant_vector R::as_dates(const std::vector<std::string>& dates, const std::string format) {
		variant_vector tm_dates;
		for (const auto& date : dates) {
			std::istringstream ss(date + "T00:00:00Z ");
			std:tm tm;
			ss >> std::get_time(&tm, format.c_str());
			auto time = mktime(&tm);
			r_date d{ tm };
			tm_dates.push_back(d);
		}
		return tm_dates;
	}

	variant_vector as_dates(std::vector<std::string>&& dates, const std::string format) {
		variant_vector tm_dates;
		for (const auto& date : dates) {
			std::istringstream ss(date + "T00:00:00Z ");
			std:tm tm;
			ss >> std::get_time(&tm, format.c_str());
			auto time = mktime(&tm);
			r_date d{ tm };
			tm_dates.push_back(d);
		}
		return tm_dates;
	}

}
