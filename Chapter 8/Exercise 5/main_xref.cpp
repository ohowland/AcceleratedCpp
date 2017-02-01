#include <iostream>

#include "xref.h"
#include "split.h"

using namespace std;

int main()
{
	my_ostream_iterator<pair<string, vector<int> > out_it(cout, " ");
	xref(cin, split, out_it);
	return 0;
}
