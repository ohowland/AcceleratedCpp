#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "find_url.h"

int main()
{
	std::ifstream file;
	std::string input;
	std::vector<std::string> temp_urls, urls;

	file.open("urls.txt");
	while (getline(file, input)) {
		temp_urls = find_urls(input);

		if (!temp_urls.empty())
			std::copy(temp_urls.begin(), temp_urls.end(), back_inserter(urls));
	}

	for (std::vector<std::string>::const_iterator iter = urls.begin();
		 iter != urls.end(); ++iter)
		std::cout << *iter << std::endl;

	return 0;
}

