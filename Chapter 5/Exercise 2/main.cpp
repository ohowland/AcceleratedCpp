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

int main()
{
	
	ifstream infile("students.txt");

	list<Student_info> students;
	list<Student_info> failures;
	Student_info record;

	// Read and store all records, find the length of hte longest name;
	while (read(infile, record)) {
		students.push_back(record);
	}
	
	failures = extract_fails(students);

	/* for (vector<Student_info>::const_iterator iter = failures.begin();
		 iter != failures.end(); ++iter) {
		cout << (*iter).name << endl;
	}*/
	return 0;
}
