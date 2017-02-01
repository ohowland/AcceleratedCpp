#include <iostream>
#include <vector>
#include <string>
#include "frame.h"

using std::cout;		using std::cin;
using std::endl;		using std::vector;
using std::string;		using std::getline;

int main()
{
	vector<string> lines;
	vector<string> post;
	string s;
	while (getline(cin, s))
		lines.push_back(s);

	post = frame(lines);

	for (vector<string>::const_iterator iter = post.begin();
		 iter != post.end(); ++iter) {
	
		cout << *iter << endl;
		
	}

	return 0;
}
