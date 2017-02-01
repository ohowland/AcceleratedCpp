#include <string>
#include <vector>
#include <iostream>
#include "Student_info.h"
#include "grade.h"

using std::istream;				using std::vector;

Student_info::Student_info(): midterm(0), final(0) { ;}
Student_info::Student_info(istream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);

	// :: insists on using a version that is not a memeber of anything.
	// this allows to call to reach the version of grade defined in
	// grade.h
	course_grade = ::grade(midterm, final, homework);
	return in;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);
		
		in.clear();
	}

	return in;
}

