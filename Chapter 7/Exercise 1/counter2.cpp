// order a map by value
// probably to show the weakness of map.

#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using std::string;	using std::cin;
using std::map;		using std::cout;
using std::endl;	
using std::max;		using std::vector;

int main()
{
	map<string, int> count;
	map<int, vector<string> > byFreq;
	
	string input;
	while(cin>>input)
		++count[input];	
	
	for (map<string, int>::iterator iter = count.begin();
			 iter != count.end(); ++iter) {
		byFreq[iter->second].push_back(iter->first);
	}

	for (map<int, vector<string> >::const_iterator iter = byFreq.begin();
		 iter != byFreq.end(); ++iter) {
		cout << "freqency: " << iter->first << endl;

		for (vector<string>::const_iterator it = iter->second.begin();
			 it != iter->second.end(); ++it)
				cout << *it << endl;
	}
	
	return 0;
}

