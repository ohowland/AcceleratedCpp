#include <cstdarg>
#include <memeory>

template <class T> class lists {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T& reference;
	typedef T& const_reference;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;

	list() { resize(0); };

	const_iterator begin() const { return data; }
	const_iterator end() const { return avail; }

	
private:

	iterator data;
	iterator avail;
};


