/*  This program helps a student compute their final grade.
	40% comes from final exam, 20% from midterm, and 40%
	from homework. */

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::setprecision;
using std::cout;			using std::string;
using std::endl;			using std::streamsize;
using std::sort;			using std::vector;
using std::domain_error;	using std::max;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// Read and store all records, find the length of hte longest name;
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0;
		 i != students.size(); ++i) {

		// write the name, padded on the right to maxlen + 1 char.
		cout << students[i].name
		     << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}
