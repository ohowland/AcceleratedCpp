#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <time.h>

#include "gen_sentence.hpp"

using namespace std;

int main()
{
	ifstream file;
	file.open("sentence_table.txt");
	srand(time(NULL));
	
	// generate the sentence
	list<string> sentence;
	gen_sentence(read_grammar(cin), back_inserter(sentence));

	// write the first word, if any
	list<string>::const_iterator it = sentence.begin();
	
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while (it != sentence.end()) {
		cout << " " << *it;
		++it;
	}

	cout << endl;
	return 0;
}
