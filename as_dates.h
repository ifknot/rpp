#pragma once

#include "types.h"

#include "conversions.h"

namespace R {

	/**
	* @brief (R-ish) as_dates convert between string representations and objects of type r_date representing
	* calendar dates.
	* 
	* @param dates
	*/
	variant_vector as_dates(const std::vector<std::string>& dates, const std::string format = "%Y-%m-%d");

	/**
	* @brief (R-ish) as_dates convert between string representations and objects of type r_date representing
	* calendar dates.
	* 
	* @param dates 
	*/
	variant_vector as_dates(std::vector<std::string>&& dates, const std::string format = "%Y-%m-%d");
	
}