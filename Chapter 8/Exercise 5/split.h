#ifndef GUARD_split_h
#define GUARD_split_h

#include <string>
#include <algorithm>
#include <cctype>

using std::find_if;
using std::isspace;
using std::string;

inline bool space(char c) {
	return isspace(c);
}

inline bool not_space(char c) {
	return !isspace(c);
}

template <class OutputIterator>
void split(const std::string& s, OutputIterator b)
{
	typedef std::string::const_iterator iter;
	iter i = s.begin();

	while (i != s.end()) {
	
		i = find_if(i, s.end(), not_space);
		
		iter j = find_if(i, s.end(), space);

		if (i != s.end())
			*b++ = string(i,j);
			i = j;
	}
}

#endif
