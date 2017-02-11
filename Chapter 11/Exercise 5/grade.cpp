#include <stdexcept>

#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::domain_error;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute final grade from components.
double grade(double midterm, double final, const std::vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}
