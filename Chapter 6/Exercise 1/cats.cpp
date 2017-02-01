#include <vector>
#include <string>
#include <iostream>
#include "width.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;


vector<string> vcat(const vector<string>& top,
				    const vector<string>& bottom)
{
	// copy the top picture
	vector<string> ret = top;
	ret.insert(ret.end(), bottom.begin(), bottom.end());
	return ret;
}

vector<string>
hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	typedef vector<string>::const_iterator iter;

	// add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;

	// indicies to look at elements from left and right respectivly
	iter it_l = left.begin();
	iter it_r = right.begin();

	// continue until we've seen all rows from both pictures
	while (it_l != left.end() || it_r != right.end()) {
		// construct new string to hold characters from both pictures
		string s;

		// copy a row from the left-hand side, if there is one
		if (it_l != left.end())
			s = *it_l++;

		// pad to full width
		s += string(width1 - s.size(), ' ');

		// copy a row from the right-hand size, if there is one
		if (it_r != right.end())
			s += *it_r++;

		// add s to the picture we're creating
		ret.push_back(s);
	}

	return ret;
}
