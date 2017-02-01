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
#include <map>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::setprecision;
using std::cout;			using std::string;
using std::endl;			using std::streamsize;
using std::sort;			using std::vector;
using std::domain_error;	using std::max;
using std::map;				using std::pair;

char get_letter(const Student_info& student, 
				const map<char, vector<double> >& scheme) 
{
	for (map<char, vector<double> >::const_iterator iter = scheme.begin();
		 iter != scheme.end(); ++iter) {
		if (student.grade < iter->second[0] &&
			student.grade >= iter->second[1])
			return iter->first;
	}
	return '?';
}

int main()
{
	map<char, int> grade_freq;
	grade_freq['A'] = 0;
	grade_freq['B'] = 0;
	grade_freq['C'] = 0;
	grade_freq['D'] = 0;
	grade_freq['F'] = 0;

	map<char, vector<double> > grade_sche;
	grade_sche['A'].push_back(101);
	grade_sche['A'].push_back(90);
	grade_sche['B'].push_back(90);
	grade_sche['B'].push_back(80);
	grade_sche['C'].push_back(80);
	grade_sche['C'].push_back(70);
	grade_sche['D'].push_back(70);
	grade_sche['D'].push_back(60);
	grade_sche['F'].push_back(60);
	grade_sche['F'].push_back(0);
	

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
				char g = get_letter(students[i], grade_sche);
				cout << g << '(' << students[i].grade << ')';
				++grade_freq[g];
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	cout << endl << "grade breakdown:" << endl;
	for (map<char, int>::const_iterator iter = grade_freq.begin();
		 iter != grade_freq.end(); ++iter)
		cout << iter->first << ": " 
			 << iter->second << endl;
	
	return 0;
}
