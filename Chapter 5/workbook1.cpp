#include <iostream>
#include <cctype>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

#include "Student_info.h"
#include "grade.h"

using std::cout;	using std::string;
using std::endl;    using std::max;
using std::vector;
using std::list;

bool fgrade (const Student_info& s)
{
	return grade(s) < 60;
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

/* Print by iterator (usused)
for (vector<Student_info>::const_iterator iter = students.begin();
	 iter != students.end(); ++iter) {
    cout << iter->name <<endl;
*/

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string boarder(maxlen + 4, '*');

	ret.push_back(boarder);

	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] + 
					  string(maxlen - v[i].size(), ' ') + " *");
	}
	
	ret.push_back(boarder);

	return ret;
}

vector<string> vcat(const vector<string>& top,
				    const vector<string>& bottom)
{
	// copy the top picture
	vector<string> ret = top;
	
	/* old way of copy the bottom picture
	for (vector<string>::const_iterator it = bottom.begin();
		 it != bottom.end(); ++it)
		ret.push_back(*it); */

	// equivalent to above ^^
	ret.insert(ret.end(), bottom.begin(), bottom.end());

	return ret;
}

vector<string>
hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	// add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;

	// indicies to look at elements from left and right respectivly
	vector<string>::size_type i = 0, j = 0;

	// continue until we've seen all rows from both pictures
	while (i != left.size() || j != right.size()) {
		// construct new string to hold characters from both pictures
		string s;

		// copy a row from the left-hand side, if there is one
		if (i != left.size())
			s = left[i++];

		// pad to full width
		s += string(width1 - s.size(), ' ');

		// copy a row from the right-hand size, if there is one
		if (j != right.size())
			s += right[j++];

		// add s to the picture we're creating
		ret.push_back(s);
	}

	return ret;
}
