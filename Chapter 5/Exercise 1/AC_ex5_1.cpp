#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;		using std::vector;
using std::cin;			using std::string;
using std::endl;		using std::getline;
using std::sort;

struct permu{string line;
			 int index;
			};

// to sort permu.
bool compare(permu& x, permu& y)
{
	return x.line < y.line;
}

// returns a string split and swapped at index.
string split_swap(const string& line, int index)
{
	string tmp;


	for (string::const_iterator iter = line.begin() + index;
		 iter != line.end(); ++iter)  {
		
		// remove leading whitespace.
		if (iter == line.begin() + index && *iter == ' ')
			;
		else
			tmp.push_back(*iter);
	}
	
	tmp.push_back(' ');
	for (string::const_iterator iter = line.begin();
		 iter != line.begin() + index; ++iter) {
			tmp.push_back(*iter);
	}

	return tmp; 
}

// returns a string split and swapped at index.
string split_swap(permu& p)
{
	return split_swap(p.line, p.index);
}

int main()
{
	string input;
	vector<permu> p;
	permu set;

	while (getline(cin, input)) {

		// Initalize stucture 'permu', which will hold
		// permutations of 'input'.
		set.line = input;
		set.index = 0;
		p.push_back(set);

		// Find the indexes for permutation.
		int n = 0;
		for (string::iterator iter = input.begin();
		 	 iter != input.end(); ++iter, ++n) {
			// Scan for spaces, mark location with pointer.
			if (isspace(*iter)) {
				set.line = input;
				set.index = n;
				p.push_back(set);
			}
		}
	}
	
	cout << endl;
	
	// Create the permuted strings based in index of rotation.
	for (vector<permu>::iterator iter = p.begin();
		 iter != p.end(); ++iter) {	
		(*iter).line = split_swap(*iter);
		(*iter).line = string(4, ' ') + (*iter).line; // add tab.
		(*iter).index = (*iter).line.size()-(*iter).index; // reverse index.
	}

	// Sort the permutation vector based on p.line string.
	sort(p.begin(),p.end(),compare);

	// Rotate strings back to original position.
	for (vector<permu>::iterator iter = p.begin();
		 iter != p.end(); iter++) {
			
		cout << split_swap(*iter) << endl;
	}	
	
	return 0;
}
