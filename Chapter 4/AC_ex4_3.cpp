#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cin;		using std::vector;
using std::cout;	using std::max;
using std::endl;
using std::setw;

int digits(int n)
{
	int base = 10;
	int count = 0;
	do {
		n /= base;
		++count;
	} while(n);

	return count;
}

int main()
{
	vector<int> n;
	vector<int> s;
	int end = 10;

	// Build two vections
	// @param n = integer
	// @param s = square of integer n
	for (int i = 0 ; i <= end; ++i) {
		n.push_back(i);
		s.push_back(i*i);
	}

	// Get vector size for constant width calculation.
	vector<int>::size_type vec_sz;
	vec_sz = n.size();
	end = (int) vec_sz;

	int offset1 = digits(n[vec_sz-1]);
	int offset2 = digits(s[vec_sz-1]) + 1;

	// print vectors
	for (int i = 0; i != end; ++i) {
		cout << setw(offset1)
			 <<	n[i]
			 << setw(offset2)
			 << s[i] << endl;
	}

	return 0;
}
