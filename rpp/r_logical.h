
#pragma once

#include <ostream>

#define TRUE R::r_logical{true}

#define FALSE R::r_logical{false}

namespace R {

	/**
	 * A separate logical type to prevent C++ implicitly (i.e. silently) coercing bool to integer!
	 */
	struct r_logical {
		bool b{true};
	};

}

std::ostream& operator<<(std::ostream& os, const R::r_logical& b);

bool operator == (const R::r_logical& lhs, const R::r_logical& rhs);

bool operator < (const R::r_logical& lhs, const R::r_logical& rhs);