#include "tail.h"

#include <algorithm>

namespace R {



	variant_vector tail(const variant_vector& x, int n) {
		variant_vector v(x.rbegin(), (x.size() < n) ? x.rend() : x.rbegin() + 6);
		std::reverse(v.begin(), v.end());
		return v;
	}

	data_frame tail(const data_frame& x, int n) {
		data_frame df;
		for (const auto& [key, vctr] : x) { // keys as column headings
			df[key] = tail(vctr, n);
		}
		return df;
	}

}