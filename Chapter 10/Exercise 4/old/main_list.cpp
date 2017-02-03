#include <iostream>
#include <list>
#include <string>
#include "lists.h"

int main(int argc, char** argv)
{
	lists list_obj;

	if (argc > 1) {
		// std::cout << argv[1] << std::endl;
		list_obj.add_str(argv[1]);
			
		for (int i = 2; i != argc; i++) {
			// std::cout << argv[i] << std::endl;
			list_obj.add_str(argv[i]);
		}
	}

	std::list<std::string> x = list_obj.strpt();
	for (std::list<std::string>::const_iterator iter = x.begin();
		iter != x.end(); iter++)
			std::cout << *iter << std::endl;

	return 0;
}
