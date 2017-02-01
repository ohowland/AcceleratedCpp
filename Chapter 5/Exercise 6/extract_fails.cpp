#include <list>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;
using std::list;

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	typedef vector<Student_info>::size_type vec_sz;
	vec_sz i = 0;
	vec_sz size = students.size();

	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
		} else {
			students.insert(students.begin(), students[i]);
			++i;
			}
		++i;
	}
	
	students.resize(size - fail.size());
	return fail;
}
