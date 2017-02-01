#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <vector>
#include <string>
#include "Student_info.h"

double aux_grade(const Student_info&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);
double final_analysis(const std::vector<Student_info>&,
					  double typec(const Student_info&));

#endif
