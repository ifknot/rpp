#include <iostream>

#include "R.h"

using namespace R;

// TODO: in (return r_logical)
// TODO: which (only accept vv of r_logical)
// TODO: head
// TODO: tail

int main() {

	std::cout << "RPP\n\n";

	
	R::data_frame d;

	d["id"] = { 1, 2, 3, 4, 5 };
	d["name"] = { "Rick", "Dan", "Mary", "Ryan", "Gary" };
	d["salary"] = { 623.3, 515.2, 611.0, 729.0, 843.25 };
	d["start_date"] = as_dates({ "2013-09-23", "2012-01-01", "2015-03-27", "2014-11-15", "2014-05-11" }, "%Y-%m-%d");
	d["male"] = { TRUE, TRUE, FALSE, TRUE, TRUE };

	// print out data table 
	std::cout << d << '\n';

	// accessing data does need prior knowledge of the column data type
	//auto money = std::get<_num>(d["salary"][1]);

	// but C++ is strongly typed so there we go
	//std::cout << std::get<_str>(d["name"][1]) << " earns $" << money << '\n';

	//if (money == range<r_numeric>(d["salary"]).first) {
		//std::cout << std::get<_str>(d["name"][1]) << " earns the least" << "\n\n";
	//}

	//std::cout << d["name"] << "\n\n";

	/*
	std::cout << sort<r_integer>(d["id"]) << "\n\n";
	std::cout << unique<r_integer>(d["id"]) << "\n\n";
	std::cout << sort<r_integer>(unique<r_integer>(d["id"])) << "\n\n";
	std::cout << unique<r_integer>(sort<r_integer>(d["id"])) << "\n\n";
	std::cout << as_string(sort<r_integer>(d["id"])) << "\n\n";
	*/
	/*
	std::cout << sort<r_string>(d["name"]) << "\n\n";
	std::cout << unique<r_string>(d["name"]) << "\n\n";
	std::cout << sort<r_string>(unique<r_string>(d["name"])) << "\n\n";
	std::cout << unique<r_string>(sort<r_string>(d["name"])) << "\n\n";
	*/
	/*
	std::cout << sort<r_numeric>(d["salary"]) << "\n\n";
	std::cout << unique<r_numeric>(d["salary"]) << "\n\n";
	std::cout << sort<r_numeric>(unique<r_numeric>(d["salary"])) << "\n\n";
	std::cout << unique<r_numeric>(sort<r_numeric>(d["salary"])) << "\n\n";
	*/
	
	//std::cout << sort<r_date>(d["start_date"]) << "\n\n";
	//std::cout << unique<r_date>(d["start_date"]) << "\n\n";
	//std::cout << sort<r_date>(unique<r_date>(d["start_date"])) << "\n\n";
	//std::cout << unique<r_date>(sort<r_date>(d["start_date"])) << "\n\n";
	//std::cout << as_string(sort<r_date>(d["start_date"])) << "\n\n";
	
	//std::cout << sort<r_logical>(d["male"]) << "\n\n";
	//std::cout << unique<r_logical>(d["male"]) << "\n\n";
	//std::cout << sort<r_logical>(unique<r_logical>(d["male"])) << "\n\n";
	//std::cout << unique<r_logical>(sort<r_logical>(d["male"])) << "\n\n";
	//std::cout << as_string(sort<r_logical>(d["male"])) << "\n\n";

	//std::cout << unique<r_date>(as_dates({ "2013", "2013", "2012", "2015", "2014", "2014", "2013" }, "%Y")) << "\n\n";

	//std::cout << factor<r_date>(d["start_date"]) << "\n\n";

	//std::cout << sort<r_date>(d["start_date"], true) << "\n\n";

	auto ldf = split<r_logical>(d, d["male"]);

	std::cout << ldf << "\n\n";

	//std::cout << split<r_logical>(d, { TRUE, TRUE, FALSE, TRUE, TRUE }) << "\n\n";

	//auto salary_range = range<r_numeric>(d["salary"]);

	//auto found = match<r_numeric>(d["salary"], { salary_range.second });

	//if (found.size()) {
		//std::cout << std::get<_str>(d["name"][std::get<r_integer>(found.front())]) << " earns the most $" << salary_range.second << "\n\n";
	//}

	//data_frame df;

	//df["x"] = { 2, 1, 4, 9 };
	//df["y"] = { 4, 1, 15, 80 };
	//df["shape"] = { 'b', 'b', 'a', 'a' };
	//df["bool"] = { TRUE, TRUE, FALSE, FALSE };

	//std::cout << df << "\n\n";
	
	//std::cout << match_all<r_raw>(df["shape"], {'a', 'b', 'c'}) << "\n\n";

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

	auto mpg = read_csv("mpg.csv");

	//std::cout << names(mpg) << "\n\n";

	try {
		mpg["year"] = as_dates({ mpg["year"] }, "%Y");
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	std::cout << head(mpg);

	//if (!dirty<_num>(mpg["displ"]).size()) {

		//split<r_date>(mpg, mpg["year"]);

	//}

	//std::cout << sort<r_date>(mpg["year"]);

	//auto spl = split<r_date>(mpg, mpg["year"]);

	auto spl = split<r_integer>(mpg, mpg["cyl"]);
	
	std::cout << spl << "\n\n";

	//data_frame data;

	//data["id"] = { "A", "B", "B", "C", "B", "A" };
	//data["x1"] = { 1, 2, 3, 4, 5, 6 };
	//data["x2"] = { 11, 12, 13, 14, 15, 16 };

	//std::cout << data;

	//auto list = split<r_string>(data, data["id"]);
	//std::cout << list;

}