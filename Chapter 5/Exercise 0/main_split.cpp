#include <iostream>
#include <vector>
#include <string>
#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	string s;

	while (getline(cin, s)) {
		vector<string> v = split(s);

		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	return 0;
}
