#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cin;		using std::vector;
using std::cout;	
using std::endl;	using std::setprecision;
using std::setw;

int digits(double n, int prec)
{
	float base = 10;
	int count = 0;
	do {
		n /= base;
		++count;
	} while(n >= 1);

	return count + prec;
}

int main()
{
	vector<double> n;
	vector<double> s;
	int prec = 3;

	// Build two vections
	// @param n = integer
	// @param s = square of integer n
	int end = 100;
	for (double i = 0; i <= end; i = i += 0.5) {
		n.push_back(i);
		s.push_back(i*i);
	}

	// Get vector size for constant width calculation.
	vector<double>::size_type vec_sz;
	vec_sz = n.size();
	end = (int) vec_sz;

	int offset1 = digits(n[vec_sz-1], prec);
	int offset2 = digits(s[vec_sz-1], prec) + 1;

	// print vectors
	int prec_last = cout.precision();
	for (int i = 0; i != end; ++i) {
		cout << setprecision(prec)
			 << setw(offset1)
			 <<	n[i]
			 << setw(offset2)
			 << s[i] 
			 << endl;
	}
	cout << setprecision(prec_last);

	return 0;
}
