#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <exception>
#include <string>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include "analysis.h"

using std::cin;				using std::ostream;
using std::cout;			using std::string;
using std::endl;
using std::vector;
using std::domain_error;

double aux_grade(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double average(const vector<double>& v)
{
	// defined in <numeric>
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}


// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}
