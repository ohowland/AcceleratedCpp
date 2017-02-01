#include <list>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::list;

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else ++iter;
	}
	return fail;
}

list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else ++iter;
	}
	return fail;
}
