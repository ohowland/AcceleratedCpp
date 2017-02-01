
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include "split.h"

int main()
{
	std::string s;
	while (getline(std::cin, s))
		split(s, std::ostream_iterator<std::string>(std::cout, "\n"));
	return 0;
}
