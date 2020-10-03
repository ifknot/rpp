#include "head.h"

namespace R {

	variant_vector head(const variant_vector& x, int n) {
		return variant_vector (x.begin(), (x.size() < n) ? x.end() : x.begin() + 6);
	}

	data_frame head(const data_frame& x, int n) {
		data_frame df;
		for (const auto& [key, vctr] : x) { // keys as column headings
			df[key] = head(vctr, n);
		}
		return df;
	}

	

}
