#ifndef GUARD_xref_h
#define GUARD_xref_h

#include <map>
#include <string>
#include <vector>
#include <istream>
#include "split.h"

template <class OutputIterator>
OutputIterator xref (std::istream& in, 
					 void find_words(const std::string&, std::back_insert_iterator<std::vector<std::string> >),
					 OutputIterator b) {
	std::string line;
	int line_number = 0;
	std::map<std::string, std::vector<int> > ret;

	// read the next line
	while (getline(in, line)) {
		++line_number;

		// break the input line into words.
		std::vector<std::string> words;
		find_words(line, back_inserter(words));
	
		for (std::vector<std::string>::const_iterator it = words.begin();
			 it != words.end(); ++it)
			ret[*it].push_back(line_number);
		}	
	
	copy(ret.begin(), ret.end(), b);

	return b;
}

#endif
