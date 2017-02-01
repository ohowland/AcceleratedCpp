#include <vector>
#include <string>
#include "width.h"

using std::string;
using std::vector;

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
