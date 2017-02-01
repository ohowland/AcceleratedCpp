#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	double x, y; 

	cout << "Enter two numbers: ";
	cin >> x >> y;
	x > y ? cout << x << endl 
		  : cout << y << endl;

	return 0;
}
