// exercise 5.7, countdown.

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	const int start = 10;
	const int end = -5;

	for (int i = start; i >= end; --i) 
		cout << i << endl;
	return 0;
}
