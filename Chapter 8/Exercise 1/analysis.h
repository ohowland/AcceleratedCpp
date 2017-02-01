#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <vector>
#include <string>
#include <algorithm>
#include "Student_info.h"
#include "median.h"

double aux_grade(const Student_info&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);

template <class Function>
double analysis(const std::vector<Student_info>& students, 
				Function grading_function)
{
	std::vector<double> grades;

	std::transform(students.begin(), students.end(),
			  	   back_inserter(grades), grading_function);
	
	return median(grades);
}

// I didn't think to write this (from book-exercise on github)
template <class Function>
void write_analysis(std::ostream& out, const std::string& name,
				    const std::vector<Student_info>& did,
					const std::vector<Student_info>& didnt,
					Function grading_function)
{
	out << name << ": median(did) = " 
			  << analysis(did, grading_function)
			  << ", median(didnt) = " 
			  << analysis(didnt, grading_function)
			  << std::endl;
}

#endif
