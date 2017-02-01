#include <iostream>
#include <vector>
#include <string>
#include "swap.h"

using std::cout;		using std::vector;
using std::cin;			using std::string;
using std::endl;

int main()
{
	typedef char type; 
	
	type input;
	vector<type> cnt;
	
	while (cin>>input)
		cnt.push_back(input);
	
	cout << "forward..." << endl;
	for (vector<type>::const_iterator iter = cnt.begin();
		 iter != cnt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	reverse_two(cnt.begin(), cnt.end());
	
	cout << "reverse..." << endl;
	for (vector<type>::const_iterator iter = cnt.begin();
		 iter != cnt.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}
