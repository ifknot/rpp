#include "overloads.h"

#include <iomanip>

bool operator>(const R::r_date& lhs, const R::r_date& rhs) {
	return lhs.is_greater(rhs);
}

bool operator==(const R::r_date& lhs, const R::r_date& rhs) {
	return lhs.is_equal(rhs);
}

std::ostream& operator<<(std::ostream& os, const R::r_date& date) {
	os << std::put_time(&date.tm, date.format.c_str());
	return os;
}

std::ostream& operator<<(std::ostream& os, const R::variant_vector& vv) {
	for (const auto& v : vv) {
		std::visit([&os](auto&& arg) {os << arg << '\t'; }, v);
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const R::variant_factor& vf) {
	os << vf.first << "\n Levels: " << vf.second;
	return os;
}

std::ostream& operator<<(std::ostream& os, const R::data_frame& df) {
	size_t sz{ 0 };
	for (const auto& [key, vctr] : df) { // keys as column headings
		os << '\t' << key;
		sz = vctr.size();
	}
	std::cout << '\n';
	for (const auto& [key, vctr] : df) { // column variant type index
		os << '\t' << "(" << vctr.front().index() << ")";
	}
	std::cout << '\n';
	for (size_t i{ 0 }; i < sz; ++i) { // records
		std::cout << i;
		for (const auto& [key, vctr] : df) {
			std::visit([&os](auto&& arg) {os << '\t' << arg; }, vctr[i]);
		}
		os << '\n';
	}
	return os;
}

