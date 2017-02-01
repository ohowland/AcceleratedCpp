#include <iostream>
#include <string>
#include <vector>
#include "split.h"
#include "palendrome.h"

using std::cin;		using std::cout;
using std::endl;	using std::string;
using std::vector;

int main()
{
	string input;
	vector<string> input_t, output_t;
	typedef vector<string>::const_iterator it;

	while(getline(cin, input))
		input_t.push_back(input);

	for (it iter = input_t.begin(); iter != input_t.end(); ++iter)
	{
		output_t = split(*iter);
		for (it iter = output_t.begin(); iter != output_t.end(); ++iter)
		{
			if (is_palendrome(*iter))
				cout << *iter << endl;
		}
	}
	return 0;
}
