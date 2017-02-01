#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <fstream>

using std::cout;		using std::endl;
using std::string;		using std::vector;
using std::ifstream;

int main()
{
	ifstream file;
	string input, output;
	vector<string> input_t;

	file.open("cat.txt");
	while (file>>input)
		input_t.push_back(input);	

	output = accumulate(input_t.begin(), input_t.end(), output);
	cout << output << endl;

	return 0;
}
