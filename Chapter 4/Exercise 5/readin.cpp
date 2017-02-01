#include <iostream>
#include <string>
#include <vector>
#include "readin.h"

using std::cout;	using std::string;
using std::cin;		using std::istream;
using std::endl;	using std::vector;

istream& readin(istream& ins, vector<string>& vec)
{
	if (ins) {
		vec.clear();
	
		string input;
		while (ins >> input) {
			vec.push_back(input);
		}

		ins.clear();
	}
	
	return ins;
}
