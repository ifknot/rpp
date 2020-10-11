#include "r_logical.h"

std::ostream& operator<<(std::ostream& os, const R::r_logical& b) {
	os << ((b.boolean) ? "TRUE" : "FALSE");
	return os;
}

bool operator==(const R::r_logical& lhs, const R::r_logical& rhs) {
	return lhs.boolean == rhs.boolean;
}

bool operator<(const R::r_logical& lhs, const R::r_logical& rhs) {
	return lhs.boolean < rhs.boolean;
}
