#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<string> stack;
	string word;

	stack.push_back("this should be saved");
	word = stack.back();
	stack.pop_back();	
	stack.push_back("this is now in it's place");
	
	cout << word << endl;

	return 0;
}
