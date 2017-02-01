// Acclerated C++
// Chapter 8, Ex. 2
// re-create standard library iterator algorithms.

// equal requires only input iterators
// requires: ==, ++, and *
template <class In1, class In2>
bool equal(In1 b, In1 e, In2 b2)
{
	while (*b++ == *b2++)
		if (b == e)
			return true;
	return false;
}
// (book solution)
template <class InputIterator1, class InputIterator2>
bool my_equal(InputIterator1 b, InputIterator1 e, InputIterator2 b2) {
	for ( ;b != e; ++b) {
		if (*b != *b2)
			return false;
		++b2;
	}

	return true;
}

// search requires input and output iterators
// requires: ==, ++, and *
template <class In1, class In2, class Out2>
bool search(In1 b, In1 e, Out2 b2, In2 e2)
{
	Out2 tmp = b2;
	while (b != e) {
		while (*b++ == *b2++) {
			if (b2 == e2)
				return true;
		}
		
		b2 = tmp;
	}
	
	return false;
}

// (book solution)
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 my_search(ForwardIterator1 b, ForwardIterator1 e,
						   ForwardIterator2 b2, ForwardIterator2 e2) {
	for ( ;b != e; ++b)
		if (my_equal(b2, e2, b))
			return b;
	return e;
}

// find requires input and output
template <class In, class In2, class Out>
Out find(In b, In e, In2 t)
{
	for (; b != e; b++)
		if (*b == *t)
			return b;
	return e;
}

// (book solution)
template <class InputIterator, class Type>
InputIterator my_find(InputIterator b, InputIterator e, const Type& t) {
	for ( ;b != e; ++b)
		if (*b == t)
			return b;
	return e;
}


// find_if requires input only
template <class In, class In2>
bool find_if(In b, In e, In2 p)
{
	for (; b != e; b++)
		if (*b == *p)
			return true;
	return false;
}

// (book solution)
template <class InputIterator, class Predicate>
InputIterator my_find_if(InputIterator b, InputIterator e, Predicate p) {
	for ( ;b != e; ++b)
		if (p(*b))
			return b;
	return e;
}

// copy requires input and output
template <class In, class Out>
void copy(In b, In e, Out d)
{
	for(; b != e; b++, d++)
		*d = *b;
}

// (book solution)
template <class InputIterator, class OutputIterator>
OutputIterator my_copy(InputIterator b, InputIterator e, OutputIterator d) {
	for ( ;b != e; ++b)
		*d++ = *b;
	return d;
}

//remove copy requires bidirectional and out.
template <class Bi, class Out, class In>
void remove_copy(Bi b, Bi e, Out d, In t)
{
	for (; b != e; b++)
	{
		if (*b != *t) {
			*d = *b;
			d++;
		}
	}
	return d;
}

// (book solution)
template <class InputIterator, class OutputIterator, class Type>
OutputIterator my_remove_copy(InputIterator b, InputIterator e,
							  OutputIterator d, const Type& t) {
	for ( ;b != e; ++b)
		if (*b != t)
			*d++ = *b;
	return d;
}
// ***************** completed to this point ******************

// (book solution)
template <class InputIterator, class OutputIterator, class Predicate>
OutputIterator my_remove_copy_if(InputIterator b, InputIterator e,
								 OutputIterator d, Predicate p) {
	for ( ;b != e; ++b)
		if (!p(*b))
			*d++ = *b;
	return d;
}

// (book solution)
template <class ForwardIterator, class Type>
ForwardIterator my_remove(ForwardIterator b, ForwardIterator e,
						  const Type& t) {
	ForwardIterator first_fail = b;
	for ( ;b != e; ++b)
		if (*b != t)
			*first_fail++ = *b;
	return first_fail;
}

template <class InputIterator, class OutputIterator, class Function>
OutputIterator my_transform(InputIterator b, InputIterator e,
							OutputIterator d, Function f) {
	for ( ;b != e; ++b)
		*d++ = f(*b);
	return d;
}

template <class ForwardIterator, class Predicate>
ForwardIterator my_partition(ForwardIterator b, ForwardIterator e,
							 Predicate p) {
	ForwardIterator first_fail = b;
	for ( ;b != e; ++b)
		if (p(*b)) swap(*first_fail++, *b);
	return first_fail;
}

template <class InputIterator, class Type>
Type my_accuulate(InputIterator b, InputIterator e, Type t) {
	for ( ;b != e; ++b)
		t += b;
	return t;
}
