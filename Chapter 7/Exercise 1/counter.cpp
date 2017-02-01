// order a map by value
// probably to show the weakness of map.

#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using std::string;	using std::cin;
using std::map;		using std::cout;
using std::endl;	using std::pair;
using std::max;		using std::vector;

int main()
{
	map<string, int> count;
	vector<map<string, int>::iterator> for_erase;
	string input;
	int max_val = 0;
	while(cin>>input)
		++count[input];
	
	for (map<string, int>::const_iterator iter = count.begin();
		iter != count.end(); ++iter) {
		// find the largest count
		max_val = max(max_val, iter->second);
	}
	
	while (!count.empty() && max_val != 0) {
		for (map<string, int>::iterator iter = count.begin();
			 iter != count.end(); ++iter) {
			if (iter->second == max_val) {
				cout << "key: " << iter->first 
					<< " value: " << iter->second 
					<< endl;
				count.erase(iter);
				++max_val;
				break;
			}
			
		}
		--max_val;
	}

	return 0;
}

