#include <vector>
#include <string>
#include "frame.h"
#include "width.h"

using std::vector;
using std::string;


vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	typedef vector<string>::const_iterator iter;
	string::size_type maxlen = width(v);
	string boarder(maxlen + 4, '*');

	ret.push_back(boarder);

	for (iter it = v.begin(); it != v.end(); ++it) {
		ret.push_back("* " + *it + 
					  string(maxlen - (*it).size(), ' ') + " *");
	}
	
	ret.push_back(boarder);

	return ret;
}

