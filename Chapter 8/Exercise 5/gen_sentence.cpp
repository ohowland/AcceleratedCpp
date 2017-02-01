#include <iostream>
#include "split.h"
#include "nrand.h"
#include "gen_sentence.hpp"

using namespace std;

bool bracketed(const string& s)
 {
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
 }

 // read a grammar from a grammar input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	// read input
	while (getline(in, line)) {
		// split the input into words
		vector<string> entry;
		split(line, back_inserter(entry));

		if (!entry.empty())
			// use the category to store the associated rule
			ret[entry[0]].push_back(
				Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}
