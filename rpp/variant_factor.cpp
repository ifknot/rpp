
#include "variant_factor.h"

std::ostream& operator<<(std::ostream& os, const R::variant_factor& vf) {
	os << vf.first << "\n Levels: " << vf.second;
	return os;
}
