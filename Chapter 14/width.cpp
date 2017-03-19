#include "width.h"

#include "Vec.hpp"
#include "Str.hpp"
#include <algorithm>

using std::max;

Str::size_type width(const Vec<Str>& v)
{
	Str::size_type maxlen = 0;
	for (Vec<Str>::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

