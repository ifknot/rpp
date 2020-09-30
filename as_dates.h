#pragma once

#include "containers.h"

namespace R {

	/**
	* @brief (R-ish) as_dates convert between string representations and objects of type r_date representing
	* calendar dates.
	* 
	* @param dates
	* @param format	- an override std::get_time compatible format string 
	*/
	variant_vector as_dates(const variant_vector& dates, std::string format = "");

	/**
	* @brief (R-ish) as_dates convert between string representations and objects of type r_date representing
	* calendar dates.
	* 
	* @param dates 
	*/
	variant_vector as_dates(variant_vector&& dates, std::string format = "");

	
}