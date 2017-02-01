#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "split.h"
#include "nrand.h"

using std::vector;			using std::string;
using std::map;				using std::istream;
using std::cout;			using std::cin;
using std::endl;

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

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word)) {
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

		// recusivly expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
				gen_aux(g, *i, ret);
	}
}

vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

int main()
{
	// generate the sentence
	vector<string> sentence = gen_sentence(read_grammar(cin));

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
