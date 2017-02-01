#include <iostream>
#include <vector>
#include <string>
#include "cats.h"
#include "frame.h"

using std::cout;		using std::cin;
using std::endl;		using std::vector;
using std::string;		using std::getline;

int main()
{
	vector<string> lines;
	vector<string> lines_framed;
	vector<string> lines_cat;

	string s;
	while (getline(cin, s))
		lines.push_back(s);

	lines_framed = frame(lines);

	lines_cat = vcat(lines, lines_framed);

	for (vector<string>::const_iterator iter = lines_cat.begin();
		 iter != lines_cat.end(); ++iter) {
	
		cout << *iter << endl;
		
	}

	return 0;
}
