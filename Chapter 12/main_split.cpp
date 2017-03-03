#include <iostream>
#include "split.h"
#include <vector>
#include "Str.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Str s;

	while (getline(cin, s)) {

    vector<Str> v = split(s);
/*
		for (Vec<Str>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
*/
    }
	return 0;
}
