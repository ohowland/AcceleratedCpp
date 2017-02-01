#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cin;		using std::vector;
using std::cout;	using std::max;
using std::endl;
using std::setw;


int main()
{
	int n = 0;
	int s = 0;
	int end = 100;

	for (int i = 1; i <= end; ++i) {
		n = i;
		s = i*i;
	
		cout << n << setw(10) << s << endl;
	}

	return 0;
}

