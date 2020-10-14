
#pragma once

#include <string>
#include <ctime>
#include <ostream>

namespace R {

	/**
	 * An R-ish calender date type
	 * This is the type to use if you have only dates, but no times, in your data.
	 * Default format is "%Y-%m-%d" e.g. 2020 - 09 - 30
	 * functions: as_dates, diffdates, +, -, etc
	 */
	struct r_date {

		std::tm tm{};
		std::string format{};

	};

}

std::ostream& operator<<(std::ostream& os, const R::r_date& date);

bool operator == (const R::r_date& lhs, const R::r_date& rhs);

bool operator < (const R::r_date& lhs, const R::r_date& rhs);
