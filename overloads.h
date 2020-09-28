#pragma once

#include "types.h"

#include <iostream>

bool operator > (const R::r_date& lhs, const R::r_date& rhs);

bool operator == (const R::r_date& lhs, const R::r_date& rhs);

/*-------- stream operator overloads --------*/

std::ostream& operator << (std::ostream& os, const R::r_date& date);

std::ostream& operator << (std::ostream& os, const R::r_date& date);

std::ostream& operator << (std::ostream& os, const R::variant_vector& vv);

std::ostream& operator << (std::ostream& os, const R::variant_factor& vf);

std::ostream& operator << (std::ostream& os, const R::data_frame& df);

template<typename T>		// mimic how R prints a list of data frames
std::ostream& operator << (std::ostream& os, const std::map<T, R::data_frame>& tdf) {
	for (const auto& [key, df] : tdf) { 
		os << key << '\n';	// keys on their own line
		os << df;			// then print the data frame split out by key	
	}
	return os;
}
