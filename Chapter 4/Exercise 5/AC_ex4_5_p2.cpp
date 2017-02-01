#include <iostream>
#include <string>
#include <vector>
#include "readin.h"

using std::cin;		using std::vector;
using std::cout;	using std::string;
using std::endl;

struct dict {
		string key;
		int value;
};

void qry_dict(string key, vector<dict>& d)
{
	// check for key in dictonary. increment value if it exists.
	int i = 0;
	for (vector<dict>::iterator it = d.begin(); it != d.end(); it++, i++) {
		if (key == d[i].key) {
			d[i].value += 1;
			return;
		}
	}

	// key not found, add to word dictionary.
	dict new_word;
	new_word.key = key;
	new_word.value = 1;
	d.push_back(new_word);
	
	return;	
}

int main()
{
	vector<dict> word_dict;
	vector<string> words;

	readin(cin, words);
	
	int i = 0;
	for (vector<string>::iterator it = words.begin(); it != words.end(); ++it, ++i)
	{
		qry_dict(words[i], word_dict);		
	}

	i = 0;
	for (vector<dict>::iterator it = word_dict.begin(); it != word_dict.end(); ++it, ++i)
	{
		cout << word_dict[i].key << " " << word_dict[i].value << endl;
	}
	return 0;
}

