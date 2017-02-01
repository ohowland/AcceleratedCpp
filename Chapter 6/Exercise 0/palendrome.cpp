#include <algorithm>
#include <string>

using std::string;

bool is_palendrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

