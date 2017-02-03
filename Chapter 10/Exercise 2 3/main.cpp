// for this exercise, note that pointers are random access iterators.

#include <iostream>
#include <vector>
#include "median.hpp"

using std::vector;

int main()
{
	double ar[] = {20, 90, 31, 29, 2, 32, 88, 4, 82, 83};
	size_t size = sizeof(ar)/sizeof(*ar);	

	vector<double> vec(ar, ar+size); // vector constructor.
	
	std::cout << median<double>(ar, ar+size) << std::endl;

	std::cout << median<double>(vec.begin(), vec.end()) << std::endl;

	return 0;
}
	
	
