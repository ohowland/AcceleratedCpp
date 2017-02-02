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

// example of bad pointer.
// x is a local variable, the memory containing it
// will be released at the end of the function block.
/* int* invalid_pointer()
{
	int x;
	return &x; //instant disaster.
}
*/

// is legit
int* pointer_to_static()
{
	static int x;
	return &x;
	// always returns the SAME POINTER!
}

int* pointer_to_dynamic()
{
	return new int(0);

	// creates a new int object, default initalized.
	// programmer must now call 'delete' on the pointer to this
	// object to free the memory.
}

char* duplicate_chars(const char* p)
{
	// allocate enough space; remember to add one for the null
	size_t length = strlen(p) + 1;
	char* result = new char[length];

	// copy into our newly allocated aoace and return point to first elem.
	copy(p, p + length, result);
	return result;
}

int main()
{
	const int month_lengths[] = {
		31, 29, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	std::cout << month_lengths[3] << std::endl;

	const char heymang[] = {
		'H', 'e', 'y', ' ', 'm', 'a', 'n', 'g', '\0'
	};
	
	string s1(heymang);
	string s2("Hey mang");
	
	string s3(heymang, heymang + strlen(heymang));
}
