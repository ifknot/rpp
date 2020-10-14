
#include "r_date.h"

#include <iomanip>
#include <cassert>

#include <algorithm>
 
std::ostream& operator<<(std::ostream& os, const R::r_date& date) {
	os << std::put_time(&date.tm, date.format.c_str());
    return os;
}

bool operator == (const R::r_date& lhs, const R::r_date& rhs) {
	auto t1 = std::mktime(const_cast<tm*>(&lhs.tm));
	auto t2 = std::mktime(const_cast<tm*>(&rhs.tm));
	// -1 if time cannot be represented as std::time_t 
	assert(t1 != -1 && t2 != -1);
	return t1 == t2;
}

bool operator < (const R::r_date& lhs, const R::r_date& rhs) {
	auto t1 = std::mktime(const_cast<tm*>(&lhs.tm));
	auto t2 = std::mktime(const_cast<tm*>(&rhs.tm));
	// -1 if time cannot be represented as std::time_t 
	assert(t1 != -1 && t2 != -1);
	return std::difftime(t2, t1) > 0;
}
