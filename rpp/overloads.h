#pragma once

#include "data_structures.h"

#include <iostream>
#include <map>

/*-------- stream operator overloads --------*/

std::ostream& operator << (std::ostream& os, const R::r_logical& b);

std::ostream& operator << (std::ostream& os, const R::variant_vector& vv);

std::ostream& operator << (std::ostream& os, const R::variant_factor& vf);

std::ostream& operator << (std::ostream& os, const R::data_frame& df);

std::ostream& operator << (std::ostream& os, const R::data_frame_list& dfl);

template<typename T>		// mimic how R prints a list of data frames
std::ostream& operator << (std::ostream& os, const std::map<T, R::data_frame>& tdf) {
	for (const auto& [key, df] : tdf) { 
		os << key << '\n';	// keys on their own line
		os << df;			// then print the data frame split out by key	
	}
	return os;
}
