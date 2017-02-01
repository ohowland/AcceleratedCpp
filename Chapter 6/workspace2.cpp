#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <exception>
#include <string>
#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::cin;				using std::ostream;
using std::cout;			using std::string;
using std::endl;
using std::vector;
using std::domain_error;

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
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

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(),
			  back_inserter(grades), average_grade);
	return median(grades);
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

bool pgrade(const Student_info& s)
{
	return !fgrade(s);
}

vector<Student_info>
extract_fails_slow(vector<Student_info>& students) 
{
	vector<Student_info> fail;
	
	remove_copy_if(students.begin(), students.end(),
				   back_inserter(fail), pgrade);

	students.erase(remove_if(students.begin(), students.end(),
							 fgrade), students.end());
	return fail;
}

vector<Student_info>
extract_fails(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter =
		stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());

	students.erase(iter, students.end());

	return fail;
}

bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
				   ", median(didnt) = " << analysis(didnt) << endl;

	return;
}

int main()
{
	// students who did and didn't do all their homework
	vector<Student_info> did, didnt;

	// read the student records and partition them
	Student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student)) 
			did.push_back(student);
		else
			didnt.push_back(student);
	}
	
	// check that both groups contain data
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	// do the analyses
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in",
				   optimistic_median_analysis, did, didnt);

	return 0;
}


