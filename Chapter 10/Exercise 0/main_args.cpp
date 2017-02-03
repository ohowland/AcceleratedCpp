#include <iostream>

int main(int argc, char** argv)
{
	//if there are command-line arguments, write them
	if (argc > 1) {
		std::cout << argv[1]; //write first argument
		
		// write each remaining argument with a space before it
		for (int i = 2; i != argc; ++i)
			std::cout << " " << argv[i];
	}

	std::cout << std::endl;
	return 0;
}
