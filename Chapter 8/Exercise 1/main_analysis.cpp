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
classifyScheme(vector<Student_info>& ctrue,
			   bool test(const Student_info &s))
{
	vector<Student_info>::iterator iter =
		stable_partition(ctrue.begin(), ctrue.end(), test);
	vector<Student_info> cfalse(iter, ctrue.end());
	ctrue.erase(iter, ctrue.end());
	
	cout << cfalse.size() << " " << ctrue.size() << endl;

	return cfalse;
}

int main()
{
	// students who did and didn't do all their homework
	vector<Student_info> ctrue, cfalse;
	// read the student records and partition them
	Student_info student;
	while (read(cin, student)) 
		ctrue.push_back(student);	
	
	cfalse = classifyScheme(ctrue, pgrade);

	// do the analyses
	write_analysis(cout, "median", ctrue, cfalse, aux_grade);
	write_analysis(cout, "average", ctrue, cfalse, average_grade);
	write_analysis(cout, "median of homework turned in", ctrue, cfalse, optimistic_median);

	return 0;
}
