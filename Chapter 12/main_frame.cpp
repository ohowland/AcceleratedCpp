#include <iostream>
#include <vector>
#include "Str.hpp"
#include "frame.h"

using std::cout;		using std::cin;
using std::endl;		using std::vector;
using std::getline;

int main()
{
	vector<Str> lines;
	vector<Str> post;
	Str s;
	while (getline(cin, s))
		lines.push_back(s);

	post = frame(lines);

	for (vector<Str>::const_iterator iter = post.begin();
		 iter != post.end(); ++iter) {
	
		cout << *iter << endl;
		
	}

	return 0;
}
