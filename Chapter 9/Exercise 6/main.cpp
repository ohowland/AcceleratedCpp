#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "PF_Student.hpp"

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	stable_partition(students.begin(), students.end(), compare_two);

	for (vector<Student_info>::size_type i = 0;
		 i != students.size(); ++i) {
		cout << students[i].name()
			 << string(maxlen + 1 - students[i].name().size(), ' ');

		char final_grade = students[i].pass() ? 'T' : 'F';
		streamsize prec = cout.precision();
		cout << setprecision(3) << final_grade
			 << setprecision(prec) << endl;
	}
	return 0;
}

	
