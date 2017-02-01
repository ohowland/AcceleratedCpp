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
				const vector<Student_info>& did,
				const vector<Student_info>& didnt,
				double type(const Student_info&))
{
	out << name << ": median(did) = " << final_analysis(did, type) <<
				   ", median(didnt) = " << final_analysis(didnt, type) << endl;

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
	write_analysis(cout, "median", did, didnt, aux_grade);
	write_analysis(cout, "average", did, didnt, average_grade);
	write_analysis(cout, "median of homework turned in", did, didnt, optimistic_median);

	return 0;
}
