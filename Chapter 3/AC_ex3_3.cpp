#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    /* Input to search
    string input = "The complete system shall be designed by "
	   	   "a qualified engineer to meet the minimum "
		   "requirements defined herein and the "
		   "conditions that exist at the site."; */

    string term = "the"; // search term 
	string input; // user input data structure.
	int count = 0;
   
	cout << "Enter input to search: ";
    while (cin >> input) {
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		if (input == term)
			count += 1;
	}
	cout << endl << "\"" << term << "\"" << " found " << count << " times." << endl;
    return 0;
}    
