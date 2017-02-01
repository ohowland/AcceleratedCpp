// Exercise 3.4 report longest and shortest string in input.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;			using std::string;
using std::cout;		using std::vector;
using std::endl;

int main()
{
	typedef vector<string::size_type>::size_type vec_sz;

	string input; // transfer to vector.
	vector<string::size_type> word_size; // container for input read into input.
	
	cout << "Input: ";
	
	while (cin >> input) {
		string::size_type size = input.size();
		word_size.push_back(size);
	}

	sort(word_size.begin(), word_size.end());

	vec_sz size_v = word_size.size();

	cout << "Shortest: " << word_size[0] << endl 
		 << "Longest: " << word_size[size_v-1] << endl;

	return 0;
}
