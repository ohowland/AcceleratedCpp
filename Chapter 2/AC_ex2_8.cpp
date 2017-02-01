#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int start = 1;
	int end = 10;
	int sum = 0;

	for (int i = start; i != end; i++)
		sum += i;

	cout << sum << endl;
	return 0;
}
