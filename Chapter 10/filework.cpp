#include <fstream>
#include <string>

using std::endl;
using std::string;

int main()
{
	ifstream infile("in")
	
	string file = "in";
	ifstream infile2(file.c_str());

	ofstream outfile("out");

	string s;

	while (getline(infile, s))
		outfile << s << endl;
	return 0;
}
