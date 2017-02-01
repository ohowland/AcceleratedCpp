#ifndef GUARD_swap_h
#define GUARD_swap_h

// the trick here for me was remembering '&'
// references to the location dereferenced to by *.
template <class Bi>
void swap_two(Bi& b, Bi& e)
{
	Bi tmp;
	tmp = b;
	b = e;
	e = tmp;
}

// from 8.2.5
template <class Bi>
void reverse_two(Bi b, Bi e)
{
	while (b != e) {
		--e;
		if (b != e)
			swap_two(*b++, *e);
	}
}

#endif
