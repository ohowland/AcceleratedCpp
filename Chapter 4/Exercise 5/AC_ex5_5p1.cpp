#include <iostream>
#include <string>
#include <vector>
#include "readin.h"

using std::cin;		using std::vector;
using std::cout;	using std::string;
using std::endl;

int main()
{
	vector<string> words;
	typedef vector<string>::size_type vec_sz;

	readin(cin, words);

	vec_sz size = words.size();
	cout << "Number of words: " << size << endl;	
	
	return 0;
}

