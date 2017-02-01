#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;	using std::cout;
using std::string;	using std::endl;
using std::max;		using std::cin;
using std::getline;

int center(const vector<string>& s)
{
	vector<string>::size_type maxlen = 0;
	
	// Find the maximum string length.
	for (vector<string>::const_iterator iter = s.begin();
		 iter != s.end(); ++iter) {
		maxlen = max(maxlen, (*iter).size());	
	}

	// Clear line for output.
	cout << endl;
	
	// Find left and right padding.
	string padl, padr;
	int space = 0;
	for (vector<string>::const_iterator iter = s.begin();
		 iter != s.end(); ++iter) {
		space = maxlen - (*iter).size();
		if (space > 0) {
			padl = string(space/2, ' ');
			padr = string((*iter).size() % 2 > 0 ? (space/2)-1
									  	  		 : space/2, ' ');
		} else {
			padl = '\0';
			padr = '\0';
		}
		
		// Print resulting line.	
		cout << padl << *iter << padr << endl;
	}
	return 0;
}

int main()
{
	string s;
	vector<string> input;
	while (getline(cin, s))
		input.push_back(s);

	return center(input);
}
