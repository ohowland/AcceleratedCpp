// decorate a string with stars
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	// Get username and place in variable 'name'.
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

	// construct greeting variable.
    const string greeting = "Hello, " + name + "!";

	// blanks to surround greeting.
	const int pad = 0;

	// calculate number of rows and columns.
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	// add new line
	cout << endl;
	
	// write output rows
	// invariant: written r number of rows.
	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;
		
		// invariant: written c number of columns.
		while (c != cols) {

			if (r == pad +1 && c == pad +1) {
				cout << greeting;
				c += greeting.size();
			} else {	

				if (r == 0 || r == rows - 1 ||
					c == 0 || c == cols-1)
					cout << "*";
				else 
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}

    return 0;
}
