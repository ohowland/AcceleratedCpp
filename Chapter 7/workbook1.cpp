#include <map>
#include <string>
#include <iostream>

using std::string;	using std::cin;
using std::map;		using std::cout;
using std::endl;

int main()
{
	map<string, int> count;
	string input;

	while(cin>>input)
		++count[input];

	for (map<string, int>::const_iterator iter = count.begin();
		 iter != count.end(); ++iter) {
		cout << "key: " << iter->first 
			 << " value: " << iter->second 
			 << endl;
	}

	return 0;
}

