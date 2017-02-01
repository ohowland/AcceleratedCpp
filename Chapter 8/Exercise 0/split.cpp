#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include "split.h"

using std::vector;
using std::string;

bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

template <class Out> void split(const string& str, Out os)
{
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end()) {
		// skip leading white spaces
		i = find_if(i, str.end(), not_space);
		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in [i,j)
		if (i != str.end())
			*os++ = string(i, j);

		i = j;
	}
}

// template void split<ostream_iterator<string> >(const string&, ostream_iterator<string>);
