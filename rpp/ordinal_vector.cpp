
#include "ordinal_vector.h"

std::ostream& operator<<(std::ostream& os, const R::ordinal_vector& ov) {
    for (const auto& arg : ov) {
        os << arg << '\t';
    }
    return os;
}
