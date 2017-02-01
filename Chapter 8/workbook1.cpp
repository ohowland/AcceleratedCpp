// Accelerated C++
// Chapter 8
// Workbook1.cpp
// Iterator types and template functions.

#include <vector>
#include <stdexcept>

using std::vector;

// example of template function
template <class T>
T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

// example (1) of input iterator
template <class In, class X> In find1(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
}

// example (2) of input iterator
// uses: ++, ==, !=, *, ->
template <class In,  class X> In find2(In begin, In end, const X& x)
{
	if (begin == end || *begin == x)
		return begin;
	begin++;
	return find2(begin, end, x);
}

// example of output iterator
// uses: *it = assignment, ++
// single-assignment/increment requirement
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}

// example of a forward iterator
// uses: *it, ++, ==, !=, it->member
// no single-assignment requirement
// all STL containers meet hte forward-iterator requirements
template <class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end) {
		if (*beg == x)
			*beg = y;
		++beg;
	}
}

// example of a bidirectional iterator
// uses:  --, and all forward iterator functions
template <class Bi> void reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

// example of random access iterator
// (with p and q as iterators and n as int)
// uses: p + n, p - n, n + p
// 		 p[n] equivalent to *(p + n)
// 		 p < q, p > q, p <= q, and p >= q
// 		 and all bidirectional functions
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end) {
		// find the midpoint of the range
		Ran mid = begin + (end - begin) / 2;
		// see which part of the range contains x; keep looking only in that part
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		// if we got here, then *mid == x so we're done/
		else return true;
	}
	return false;
}
