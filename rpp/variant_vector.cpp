
#include "variant_vector.h"

std::ostream& operator << (std::ostream& os, const R::variant_vector& vv) {
	for (const auto& v : vv) {
		std::visit([&os](auto&& arg) {os << arg << '\t'; }, v);
	}
	return os;
}


