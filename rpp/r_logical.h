#pragma once

#include <ostream>

namespace R {

	/**
	 * A separate logical type to prevent C++ implicitly (i.e. silently) coercing bool to integer!
	 */
	struct r_logical {
		bool boolean;
	};

}

std::ostream& operator<<(std::ostream& os, const R::r_logical& b);

bool operator == (const R::r_logical& lhs, const R::r_logical& rhs);

bool operator < (const R::r_logical& lhs, const R::r_logical& rhs);