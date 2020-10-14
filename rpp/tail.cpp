
#include <algorithm>

#include "tail.h"

namespace R {

	variant_vector tail(const variant_vector& x, size_t n) {
		variant_vector vv(x.rbegin(), (x.size() < n) ? x.rend() : x.rbegin() + 6);
		std::reverse(vv.begin(), vv.end());
		return vv;
	}

	data_frame tail(const data_frame& x, size_t n) {
		data_frame df;
		for (const auto& [key, vctr] : x) { // keys as column headings
			df[key] = tail(vctr, n);
		}
		return df;
	}

}