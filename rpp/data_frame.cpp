
#include "data_frame.h"
#include "typeof.h"

// TODO: better tab layout 
std::ostream& operator << (std::ostream& os, const R::data_frame& df) {
	size_t sz{ 0 };
	for (const auto& [key, vctr] : df) { // keys as column headings
		os << '\t' << key;
		sz = vctr.size();
	}
	os << '\n';
	for (const auto& [key, vctr] : df) { // column variant type index of the first item in the column vector
		os << '\t' << "(" << R::typeof(vctr.front()) << ")";
	}
	os << '\n';
	for (size_t i{ 0 }; i < sz; ++i) { // records
		os << i;
		for (const auto& [key, vctr] : df) {
			std::visit([&os](auto&& arg) {os << '\t' << arg; }, vctr[i]);
		}
		os << '\n';
	}	
	return os;
}
