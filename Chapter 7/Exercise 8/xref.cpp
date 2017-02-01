#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;			using std::string;
using std::map;				using std::istream;

map<string, vector<int> >
	xref (istream& in, 
		  vector<string> find_words(const string&))
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	// read the next line
	while (getline(in, line)) {
		++line_number;

		// break the input line into words.
		vector<string> words = find_words(line);

		// remember that each word occurs on the current line.
		for (vector<string>::const_iterator it = words.begin();
			 it != words.end(); ++it) {
			if (find(ret[*it].begin(), ret[*it].end(), line_number) == ret[*it].end())
				ret[*it].push_back(line_number);
		}
	}
	
	return ret;
}
