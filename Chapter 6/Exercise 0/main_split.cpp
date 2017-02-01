#include <iostream>
#include <vector>
#include <string>
#include "split.h"

using std::cin;		using std::string;
using std::cout;	using std::vector;
using std::endl;

int main()
{
	string input;
	vector<string> input_t;
	vector<string> output_t;

	while (getline(cin, input))
		input_t.push_back(input);

	for (vector<string>::const_iterator iter = input_t.begin();
		 iter != input_t.end(); ++iter) {
	
		output_t = split(*iter);

		for (vector<string>::const_iterator iter = output_t.begin();
			 iter != output_t.end(); ++iter) {
	
			cout << *iter << endl;
		}
	
	}

	return 0;
}
