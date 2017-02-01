#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include "split.h"
#include "xref.h"

using std::vector;			using std::string;
using std::map;				using std::istream;
using std::cin;				using std::cout;
using std::endl;			using std::ostringstream;

int main()
{
	// call xref using split by default
	map<string, vector<int> > ret = xref(cin);
	string::size_type max_len = 20;

	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		 it != ret.end(); ++it) {
		// write the word
		ostringstream ss;

		ss << it->first << " occurs on line(s): ";
		
		// followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		ss << *line_it; // write hte first line number
		++line_it;

		// write the rest of the line numbers, if any
		while (line_it != it->second.end()) {
			ss << ", " << *line_it;
			++line_it;
		}
		
		string str_out = ss.str();
		for (string::size_type i = 0; i != str_out.size(); ++i) {
			cout << str_out[i];
			if (i % max_len == 0)
				cout << endl;
		}

		cout << endl;	
	}
	
	return 0;
}
