#include <vector>
#include "Str.hpp"
#include "frame.h"
#include "width.h"

using std::vector;


vector<Str> frame(const vector<Str>& v)
{
	vector<Str> ret;
	Str::size_type maxlen = width(v);
	Str boarder(maxlen + 4, '*');

	ret.push_back(boarder);

	for (vector<Str>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] + 
					  Str(maxlen - v[i].size(), ' ') + " *");
	}
	
	ret.push_back(boarder);

	return ret;
}

