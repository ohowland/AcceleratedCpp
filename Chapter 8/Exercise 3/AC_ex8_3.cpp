#include <vector>
#include <stdexcept>

template <class T>
T median(std::vector<T> v)
{
	typedef typename std::vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

template <class ForwardIterator, class Type>
Type median_iter(ForwardIterator b, ForwardIterator e)
{
	sort(b, e);
	int size = (b - e);
	int mid = (size / 2) - 1;

	for (; b != (b + mid); ++b)
		;
	return mid * 2 % 2 == 0 ? 
		
	
}
							
