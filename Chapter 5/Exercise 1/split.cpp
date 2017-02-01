#include <vector>
#include <string>
#include <cctype>
#include "split.h"

using std::string;
using std::vector;
using std::isspace;


vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
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
