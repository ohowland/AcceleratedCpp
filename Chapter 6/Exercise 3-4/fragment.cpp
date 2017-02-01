// corrected version of the ex3.cpp example.

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> u(10,100);
	vector<int> v;

	copy(u.begin(), u.end(), back_inserter(v));

	for (vector<int>::const_iterator iter = v.begin();
		 iter != v.end(); iter++)
		cout << *iter << endl;
}
