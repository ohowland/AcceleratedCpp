#include <cctype>
#include <vector>

#include "split.h"
#include "Str.hpp"

using std::isspace;
using std::vector;;

vector<Str> split(const Str& s)
{
	vector<Str> ret;
	typedef Str::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {

		// ignore leading blanks.
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word:
		string_size j = i;
		while (j != s.size() && !isspace(s[j]))
			++j;
		
		// found non-whitespace characters:
		if (i != j) {
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
		
	}
	return ret;
}
