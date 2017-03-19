#include <cctype>
#include <algorithm>

#include "split.h"
#include "Str.hpp"
#include "Vec.hpp"

using std::isspace;

bool space(char c) {
    return isspace(c);
}

bool not_space(char c) {
    return !isspace(c);
}

Vec<Str> split(const Str& s)
{
	Vec<Str> ret;
    typedef Str::const_iterator iter;

    iter i = s.begin();
    while (i != s.end()) {
       i = std::find_if(i, s.end(), not_space);
       iter j = std::find_if(i, s.end(), space);

       if (i != s.end())
           ret.push_back(Str(i, j));
       i = j;
    }

    return ret;
}
