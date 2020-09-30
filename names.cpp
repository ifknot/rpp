#include "names.h"

namespace R {



	variant_vector names(data_frame& x) {
		variant_vector v;
		for (const auto& [key, vctr] : x) { // keys as column headings
			v.push_back(key);
		}
		return v;
	}

}