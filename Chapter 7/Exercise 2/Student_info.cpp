// source file for Student_info related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;	using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

// read and store student info
istream& read(istream& is, Student_info& s)
{
	Student_info temp;
	is >> s.name >> temp.midterm >> temp.final;

	read_hw(is, temp, s);
	return is;
}

// read homework grades from and input stream into a vector<double>
istream& read_hw(istream& in, Student_info& temp, Student_info& s) 
{
	if (in) {
		// get rid of previous contents
		temp.homework.clear();

		// read homework grades
		double x;
		while (in >> x)
			temp.homework.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();

		s.grade = grade(temp);
	}
	return in;
}


