#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int height;
	int base;
	int center;

	// user input
	cout << "Enter a triangle height: ";
	cin >> height;
	cout << endl;

	// triangle geometry
	base = 2*height-1;
	center = base/2 +1;

	// top of the triangle.
	string s_space(center-1,' ');
	cout << s_space << "*" << s_space << endl;

	// calculate placement of inner boundries.
	if (height > 1) {
		for (int line = 1; line != height-1; line++) {
			
			// calculate inner/outer space
			string o_space(center-line-1, ' ');
			string i_space(line*2-1, ' ');
			// combine strings
			string output = o_space + "*" + i_space + "*";
			cout << output << endl;
		}

		// base of the triangle
		string last(base, '*');
		cout << last << endl;
		cout << endl;
	}
	return 0;
}
