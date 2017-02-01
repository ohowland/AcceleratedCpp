#include <iostream>
#include <vector>
#include "readin.h"

using std::cout;	
using std::istream;
using std::vector;

istream& readin(istream& ins, vector<double>& vec)
{
	if (ins) {
		vec.clear();
	
		double input;
		while (ins >> input) {
			vec.push_back(input);
		}

		ins.clear();
	}
	
	return ins;
}
