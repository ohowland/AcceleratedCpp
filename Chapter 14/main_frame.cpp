#include <iostream>
#include "Str.hpp"
#include "frame.h"

using std::cout;		using std::cin;
using std::endl;
using std::getline;

int main()
{
	Vec<Str> lines;
	Vec<Str> post;
    lines.push_back("HEY HEY HEY");

	post = frame(lines);

	for (Vec<Str>::const_iterator iter = post.begin();
		 iter != post.end(); ++iter) {
	
		cout << *iter << endl;
	}

	return 0;
}
