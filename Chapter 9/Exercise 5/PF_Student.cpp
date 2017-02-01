#include <string>
#include <vector>
#include <iostream>
#include "PF_Student.hpp"
#include "grade.h"

using std::istream;
using std::vector;
using std::string;

Student_info::Student_info(): midterm(0), final(0) { ;}
Student_info::Student_info(istream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

bool fail(double g)
{
	return g < 60.0;
}

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	passfail = fail( ::grade(midterm, final)) ? 'F' : 'P';

	return in;
}
