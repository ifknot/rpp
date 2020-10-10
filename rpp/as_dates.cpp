#include "as_dates.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace R {

	variant_vector as_dates(const variant_vector& dates, std::string format) {
		variant_vector tm_dates;
		for (const auto& date : dates) {
			r_string d;
			switch (date.index()) {
			case _str:
				d = std::get<_str>(date);
				break;
			case _int:
				d = std::to_string(std::get<_int>(date));
				break;
			default:
				throw std::invalid_argument(std::string(__func__) + " invalid argument " + index_to_string[date.index()]);
			}
			std::istringstream ss(d);
			std::time_t t = std::time(nullptr);
			std:tm tm;
			tm = *std::localtime(&t);
			ss >> std::get_time(&tm, format.c_str());
			r_date tm_date;
			tm_date.format = format;
			tm_date.tm = tm;
			tm_dates.push_back(tm_date);
		}
		return tm_dates;
	}

	variant_vector as_dates(variant_vector&& dates, std::string format) {
		variant_vector tm_dates;
		for (const auto& date : dates) {
			r_string d;
			switch (date.index()) {
			case _str:
				d = std::get<_str>(date);
				break;
			case _int:
				d = std::to_string(std::get<_int>(date));
				break;
			default:
				throw std::invalid_argument(std::string(__func__) + " invalid argument " + index_to_string[date.index()]);
			}
			std::istringstream ss(d);
			std::time_t t = std::time(nullptr);
			std:tm tm;
			tm = *std::localtime(&t);
			ss >> std::get_time(&tm, format.c_str());
			r_date tm_date;
			tm_date.format = format;
			tm_date.tm = tm;
			tm_dates.push_back(tm_date);
		}
		return tm_dates;
	}

}
