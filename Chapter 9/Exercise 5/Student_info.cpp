#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Student_info.h"
#include "grade.h"

using std::istream;				using std::vector;
using std::ostream;				using std::string;
using std::endl;
using std::map;

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
	read_hw(in, homework);

	if (valid()) {
		course_grade = ::grade(midterm, final, homework);
	} else {
		course_grade = ::grade(midterm, final);
	}
	
	pf = !fail(course_grade);
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

void Report::gen_report(const Student_info& s)
{
	name_map[s.name()] = fail(s.grade()) ? 'F' : 'P';
}

void Report::gen_report(const vector<Student_info>& s)
{
	for (vector<Student_info>::const_iterator iter = s.begin();
         iter != s.end(); iter++) {
		
		name_map[(*iter).name()] = fail((*iter).grade()) ? 'F' : 'P';
	}

	print_report(std::cout);
}

void Report::print_report(ostream& out)
{
	for (map<string, char>::const_iterator iter = name_map.begin();
		 iter != name_map.end(); iter++) {
		out << iter->first << " " << iter->second << std::endl;
	}
}
