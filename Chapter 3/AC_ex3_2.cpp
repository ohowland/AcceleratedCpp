#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;	using std::vector;
using std::cin;		using std::sort;
using std::endl;

int main()
{
	cout << "Enter a few numbers, followed by EOF: ";
	
	double x;
	vector<double> input_vals;

	// Read input to vector.
	while (cin >> x)
		input_vals.push_back(x);

	// Get size of vector.
	typedef vector<double>::size_type vec_sz;
	vec_sz size = input_vals.size();

	// check for valid vector size.
	if (size == 0) {
		cout << endl << "No values entered." << endl;
		return 1;
	}
	
	// sort array in nondecending order
	sort(input_vals.begin(),input_vals.end());

	// Get quartile size
	vec_sz qt = size/4;
	
	for (vec_sz i = size-qt; i != size; ++i)
		cout << input_vals[i] << endl;

	return 0;
}
