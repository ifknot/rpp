
#include "typeof.h"

#include <cassert>

namespace R {

    std::string R::typeof(variant_vector x) {
        if (x.size()) {
            auto type = typeof(x.front());
            for (const auto& v : x) {
                assert(typeof(v) == type);
            }
            return type;
        }
        else {
            return "NULL";
        }
    }

}
