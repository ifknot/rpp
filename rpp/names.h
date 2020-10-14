
#pragma once

#include <string>

#include "data_structures.h"

namespace R {

	/**
	 * @brief (R-ish) get the names of a data frame 
	 * 
	 * @param x 
	 * 
	 * @todo implement names("key")<-NULL using extract 
	 * @todo implement names("key")<-"new_key" using extract and modify the node key then insert back
	 * 
	 * https://www.fluentcpp.com/2020/05/01/how-to-change-a-key-in-a-map-or-set-in-cpp/
	 * 
	 */
	variant_vector names(data_frame& x);

}