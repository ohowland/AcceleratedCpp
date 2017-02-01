#ifndef GUARD_median_h
#define GUARD_median_h

#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <iostream>

// using random access iterator. this will not work on list.
template <class RandIterator, class Type>
void median_iter(RandIterator b, RandIterator e, Type& t)
{
	int size = e - b;
	
	// fyi sort will not invalidate the iterator. 
	sort(b, e);

	// from 8.2.5:
	RandIterator mid = b + (e - b) / 2;
	std::cout << "midpoint index: " << (mid - b) << std::endl;
	
	// adapted from original median alg.
	t = size % 2 == 0 ? (*mid + *(--mid)) / 2 : *mid;
}

#endif
							
