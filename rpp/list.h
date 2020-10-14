#pragma once

#include <map>

namespace R {

	template<typename T>
	using list = std::map<r_string, T>;

}

template<typename T>
std::ostream& operator << (std::ostream& os, R::list<T>& l) {
	for (const auto& [key, item] : l) {
		os << '$' << key << '\n';	// keys on their own line
		os << item << '\n';	// then print the item (r_type, data_frame, vector, etc.)	
	}
	return os;
}
