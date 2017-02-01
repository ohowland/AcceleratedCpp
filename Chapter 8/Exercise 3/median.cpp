#include <iostream>
#include <vector>
#include <algorithm>
#include "median.h"

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	double input, output = 0;
	vector<double> container;

	while (cin >> input) {
		container.push_back(input);
	}

	// call new median function.
	median_iter(container.begin(), container.end(), output);

	// print sorted vector for debug.
	for (vector<double>::const_iterator iter = container.begin();
		 iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	cout << "-> median: " << output << endl;

	return 0;
}	
