#include <iostream>

#include "R.h"

using namespace R;

int main() {

	std::cout << "heterogeneous container\n\n";

	R::data_frame d;

	d["id"] = { 1, 2, 3, 4, 5 };
	d["name"] = { "Rick", "Dan", "Michell", "Ryan", "Gary" };
	d["salary"] = { 623.3, 515.2, 611.0, 729.0, 843.25 };
	d["start_date"] = as_dates({ "2012-01-01", "2013-09-23", "2014-11-15", "2014-05-11", "2015-03-27" });

	// print out data table 
	std::cout << d << '\n';

	// accessing data does need prior knowledge of the column data type
	auto money = std::get<r_double>(d["salary"][1]);

	// but C++ is strongly typed so there we go
	std::cout << std::get<r_string>(d["name"][1]) << " earns $" << money << '\n';

	if (money == range<r_double>(d["salary"]).first) {
		std::cout << std::get<r_string>(d["name"][1]) << " earns the least" << "\n\n";
	}

	std::cout << d["name"] << "\n\n";

	std::cout << sort<r_date>(d["start_date"]) << "\n\n";

	auto salary_range = range<r_double>(d["salary"]);

	auto found = match<r_double>(d["salary"], { salary_range.second });

	if (found.size()) {
		std::cout << std::get<r_string>(d["name"][std::get<r_integer>(found.front())]) << " earns the most $" << salary_range.second << "\n\n";
	}

	data_frame df;

	df["x"] = { 2, 1, 4, 9 };
	df["y"] = { 4, 1, 15, 80 };
	df["shape"] = { 'b', 'b', 'a', 'a' };

	std::cout << df << "\n\n";
	
	std::cout << match<r_raw>(df["shape"], variant_vector{'a', 'b', 'c'}) << "\n\n";

	//std::map<r_raw, data_frame> tdf;

	//tdf['a'] = df;

	//std::cout << tdf;

	//std::cout << sort<r_integer>(df["y"]) << "\n\n";

	//df["x"] = rescale<r_integer>(df["x"], std::pair(10, 200));
	//df["y"] = rescale<r_integer>(df["y"], std::pair(10, 300));

	//std::cout << df << "\n\n";

	//std::cout << floor(df["x"]) << "\n\n";
	//std::cout << floor(df["y"]) << "\n\n";

	//std::cout << df << "\n\n";

	//sort<r_double>(df["x"], true);

	//std::cout << df << "\n\n";

	//auto t = df["x"];

	//std::cout << unique<r_raw>(df["shape"]) << "\n\n";

	//std::cout << factor<r_raw>(df["shape"]) << "\n\n";

	//std::cout << factor<r_double>(df["x"]) << "\n\n";

	//std::cout << factor<r_char, r_string>(df["shape"], {"BB", "AA"}) << "\n\n";

	//std::cout << factor<r_float>(df["x"]) << "\n\n";

	//std::cout << df << "\n\n";

	//auto mpg = read_csv("mpg.csv");

	//std::cout << unique<r_string>(sort<r_string>(mpg["model"], true)) << "\n\n";

	//std::cout << sort<r_string>(unique<r_string>(mpg["model"])) << "\n\n";

	//std::cout << mpg << "\n\n";

}