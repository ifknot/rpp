#include "overloads.h"

#include <variant>

#include "typeof.h"

std::ostream& operator << (std::ostream& os, const R::variant_vector& vv) {
	for (const auto& v : vv) {
		std::visit([&os](auto&& arg) {os << arg << '\t'; }, v);
	}
	return os;
}

// TODO: better tab layout 
std::ostream& operator << (std::ostream& os, const R::data_frame& df) {
	size_t sz{ 0 };
	for (const auto& [key, vctr] : df) { // keys as column headings
		os << '\t' << key;
		sz = vctr.size();
	}
	std::cout << '\n';
	for (const auto& [key, vctr] : df) { // column variant type index of the first item in the column vector
		os << '\t' << "(" << R::typeof(vctr.front()) << ")";
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

std::ostream& operator<<(std::ostream& os, const R::data_frame_list& dfl) {
	for (const auto& [key, df] : dfl) {
		os << '$' << key << '\n';
		os << df;
	}
	return os;
}

