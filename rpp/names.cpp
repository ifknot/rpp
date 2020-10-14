#include "names.h"

namespace R {



	variant_vector names(data_frame& x) {
		variant_vector vv;
		for (const auto& [key, vctr] : x) { // keys as column headings
			vv.push_back(key);
		}
		return vv;
	}

}