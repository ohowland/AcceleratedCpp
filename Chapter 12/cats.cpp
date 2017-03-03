#include <vector>
#include "Str.hpp"
#include "width.h"

using std::vector;

vector<Str> vcat(const vector<Str>& top,
				    const vector<Str>& bottom)
{
	// copy the top picture
	vector<Str> ret = top;
	
	/* old way of copy the bottom picture
	for (vector<Str>::const_iterator it = bottom.begin();
		 it != bottom.end(); ++it)
		ret.push_back(*it); */

	// equivalent to above ^^
	ret.insert(ret.end(), bottom.begin(), bottom.end());

	return ret;
}

vector<Str>
hcat(const vector<Str>& left, const vector<Str>& right)
{
	vector<Str> ret;

	// add 1 to leave a space between pictures
	Str::size_type width1 = width(left) + 1;

	// indicies to look at elements from left and right respectivly
	vector<Str>::size_type i = 0, j = 0;

	// continue until we've seen all rows from both pictures
	while (i != left.size() || j != right.size()) {
		// construct new Str to hold characters from both pictures
		Str s;

		// copy a row from the left-hand side, if there is one
		if (i != left.size())
			s = left[i++];

		// pad to full width
		s += Str(width1 - s.size(), ' ');

		// copy a row from the right-hand size, if there is one
		if (j != right.size())
			s += right[j++];

		// add s to the picture we're creating
		ret.push_back(s);
	}

	return ret;
}
