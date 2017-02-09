#include <iostream>
#include <string>
#include "Vec.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	string s;
	Vec<string> v;

	while(cin >> s)
		v.push_back(s);

	for(Vec<string>::const_iterator iter = v.begin(); 
		iter != v.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
