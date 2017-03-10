#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"

using std::domain_error;	using std::vector;

double grade(double midterm, double final)
{
    return 0.5 * midterm + 0.5 * final;
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute final grade from components.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
        return grade(midterm, final, 0);
        //throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

