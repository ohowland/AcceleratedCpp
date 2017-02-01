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

bool compare_two(const Student_info& x)
{
	return x.pass();
}

bool fail(double s)
{
	return s < 60.0;
}

istream& Student_info::read(istream& in)
{
	in >> _name >> midterm >> final;
	_pass = !fail( ::grade(midterm, final));  

	return in;
}
