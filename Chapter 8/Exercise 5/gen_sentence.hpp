#include <map>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

int nrand(int);

bool bracketed(const std::string&);

Grammar read_grammar(std::istream&);

template <class OutputIterator>
OutputIterator gen_aux(const Grammar& g, const std::string& word, OutputIterator b)
{
	if (!bracketed(word)) {
		*b = word;
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
				gen_aux(g, *i, b);
	}
	return b;
}

template <class OutputIterator>
OutputIterator gen_sentence(const Grammar& g, OutputIterator b)
{
	gen_aux(g, "<sentence>", b);
	return b;
}
