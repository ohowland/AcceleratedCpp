// Accelerated C++
// Chapter 7
// Exercise 6 

#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include "split.h"
#include "nrand.h"

using std::vector;			using std::string;
using std::map;				using std::istream;
using std::cout;			using std::cin;
using std::endl;			using std::ifstream;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

bool bracketed(const string& s)
 {
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
 }

 // read a grammar from a grammar input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	// read input
	while (getline(in, line)) {
		// split the input into words
		vector<string> entry = split(line);

		if (!entry.empty())
			// use the category to store the associated rule
			ret[entry[0]].push_back(
				Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}


void gen_aux(const Grammar& g, vector<string>& stack, vector<string>& ret)
{
	string word;
	while(!stack.empty()) {
		// get the value at the top of the stack.
		word = stack.back();
		// remove the value from the stack.
		stack.pop_back();

		if (!bracketed(word)) {
			// remove from stack and place in ret
			ret.push_back(word);
		} else {
			// locate the rule that corresponds to 'word'
			Grammar::const_iterator it = g.find(word);
			if (it == g.end())
				throw std::logic_error("empty rule");

			// fetch the set of possible rules
			const Rule_collection& c = it->second;

			// from which we select at random
			const Rule& r = c[nrand(c.size())];
			
			// push rule back into the stack.
			
			for (Rule::const_reverse_iterator iter = r.rbegin(); iter != r.rend(); ++iter)
				stack.push_back(*iter);
		}

	}
}

vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	vector<string> stack;
	stack.push_back("<sentence>");
	gen_aux(g, stack, ret);
	return ret;
}

int main()
{
	ifstream file;
	file.open("sentence_table.txt");
	srand(time(0));
	
	// generate the sentence
	vector<string> sentence = gen_sentence(read_grammar(file));

	// write the first word, if any
	vector<string>::const_iterator it = sentence.begin();
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
