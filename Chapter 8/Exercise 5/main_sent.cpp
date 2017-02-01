#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <time.h>

#include "gen_sentence.hpp"

using namespace std;

int main()
{
	ifstream file;
	file.open("sentence_table.txt");
	srand(time(NULL));
	
	ostream_iterator<string> out_it(cout," ");
	gen_sentence(read_grammar(cin), out_it);
	cout << endl;

	return 0;
}
