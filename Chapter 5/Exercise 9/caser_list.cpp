#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cctype>

using std::cout;		using std::endl;
using std::cin;			using std::list;
using std::string;		using std::ifstream;

int main()
{
	list<string> caps_sort;
	string s;
	bool flag;
	
	ifstream infile("big.txt");

	while (infile >> s) {
		flag = 0;
		for (string::const_iterator iter = s.begin();
			 iter != s.end(); ++iter) {
			if (std::isupper(*iter)) 
				flag = 1;
			}
		
		if (flag) { 
			caps_sort.push_back(s);
		} else {	
			caps_sort.insert(caps_sort.begin(), s);
		}
	}
	
	/*for (list<string>::const_iterator iter = caps_sort.begin();
		 iter != caps_sort.end(); ++iter) {
			cout << *iter << ' ';
	}
	
	cout << endl;
	*/
	return 0;
}
