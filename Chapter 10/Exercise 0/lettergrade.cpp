#include <cstddef>
#include <iostream>
#include <algorithm>
#include <string>

using std::string;
using std::copy;

//size_t is an unsigned integer type that is
// appropriate to contain the size of any array.

size_t strlen(const char* p)
{
	size_t size = 0;
	while (*p++ != '\0')
		++size;
	return size;
}

string letter_grade(double grade)
{
	// static tells the compiler to initalize
	// the arrays one time only. without static
	// the variables would be initalized every call.

	//range posts for numeric grades
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	// names for the letter grades
	// the idea behind char* is that we are defining an array
	// of char POINTERS to the first char in a string literal.
	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	// computer the number of grades given the size of the array
	// and the size of a single element.
	// size of tells how much memory an object type consumes
	// in bytes. total size / element size = # of elements.
	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	for (size_t i = 0; i < ngrades; ++i) {
		if (grade >= numbers[i])
			return letters[i];
	}
	
	return "?\?\?";
}

// need to convert string argv's to double.

int main(int argc, char** argv)
{
	if (argc > 1) {
		std::cout << letter_grade(argv[1]);
		for (int i = 2; i != argc; ++i)
			std::cout << " " << letter_grade(argv[i]);
	}
	
	std::cout << std::endl;
	return 0;
}
