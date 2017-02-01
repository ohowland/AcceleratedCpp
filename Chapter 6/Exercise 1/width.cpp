#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::max;

string::size_type width_old(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	typedef vector<string>::const_iterator iter;

	for (iter it = v.begin(); it != v.end(); ++it)
		maxlen = max(maxlen, (*it).size());
	return maxlen;
}
