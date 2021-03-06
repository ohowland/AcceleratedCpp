#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Student_info.h"
#include "letter_grade.h"

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

	for (vector<Student_info>::size_type i = 0;
		 i != students.size(); ++i) {
		cout << students[i].name()
			 << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			string final_grade = letter_grade(students[i].grade());
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

	
