#pragma once

#include "types.h"

#include <iostream>

bool operator > (const R::r_date& lhs, const R::r_date& rhs);

bool operator==(const R::r_date& lhs, const R::r_date& rhs);

/*-------- stream operator overloads --------*/

std::ostream& operator<<(std::ostream& os, const R::r_date& date);

std::ostream& operator<<(std::ostream& os, const R::r_date& date);

std::ostream& operator<<(std::ostream& os, const R::variant_vector& vv);

std::ostream& operator<<(std::ostream& os, const R::variant_factor& vf);

std::ostream& operator<<(std::ostream& os, const R::data_frame& df);
