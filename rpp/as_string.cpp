
#include "as_string.h"

#include <sstream>

namespace R {

    std::string as_string(const r_type& x) {
        std::stringstream ss;
        std::visit([&ss](auto&& arg) {ss << arg; }, x);
        return ss.str();
    }

    std::string as_string(const r_type&& x) {
        std::stringstream ss;
        std::visit([&ss](auto&& arg) {ss << arg; }, x);
        return ss.str();
    }

    string_vector as_string(const variant_vector& x) {
        string_vector vv;
        for (const auto& v : x) {
            vv.push_back(as_string(v));
        }
        return vv;
    }

    string_vector as_string(const variant_vector&& x) {
        string_vector vv;
        for (const auto& v : x) {
            vv.push_back(as_string(v));
        }
        return vv;
    }

}
