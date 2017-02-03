#include <cstddef>
#include <vector>
#include <algorithm>

int main()
{
    // define NDim at compile time with size_t.
    // the implementation defines size_t as the appropriate
    // unsigned type large enough to hold the size of
    // any object.
    const size_t NDim = 3;
    double coords[NDim];
	
	// *coords dereferences the first value of coords.
	// here the first value of coords array is set to 1.5
    *coords = 1.5;

	// coords, called by itself is a random access pointer
	// we can use it as we would any random access iterator.
	// note that coords + x moves the pointer forward x.
	// pointers are valid for dimension of array + 1 in
	// either direction.
	std::vector<double>	v;
	copy(coords, coords + NDim, back_inserter(v));

	// using vector constructor from iterators.
	std::vector<double> v1(coords, coords + NDim);	
	
    return 0;
}
