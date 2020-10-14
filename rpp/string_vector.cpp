
#include "string_vector.h"

std::ostream& operator<<(std::ostream& os, const R::string_vector& sv) {
    for (const auto& arg : sv) {
        os << arg << '\t';
    }
    return os;
}
