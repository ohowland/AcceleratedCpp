#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename Rand>
T median(Rand b, Rand e)
{
	if (b == e)
		throw std::domain_error("median of an empty array");

	std::vector<T> temp;
	
	while (b++ != e)
		temp.push_back(*b);
	
	std::sort(temp.begin(), temp.end()); 

	size_t mid = temp.size()/2;

	return temp.size() % 2 ? temp[mid] : (temp[mid] + temp[mid-1]) / 2;

}


