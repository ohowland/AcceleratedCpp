/*  This program helps a student compute their final grade.
	40% comes from final exam, 20% from midterm, and 40%
	from homework. */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails.h"

using std::cin;				using std::ifstream;
using std::cout;			using std::string;
using std::endl;			using std::list;
using std::vector;

typedef vector<Student_info> student_type;

int main()
{
	
	ifstream infile("students.txt");

	student_type students;
	student_type failures;
	Student_info record;

	// Read and store all records, find the length of hte longest name;
	while (read(infile, record)) {
		students.push_back(record);
	}
	
	failures = extract_fails(students);
	
	cout << "passing students: " << students.size() << endl;
	return 0;
}
