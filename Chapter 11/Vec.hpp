

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;	

	Vec() { create(); }
	explicit Vec(std::size_t n, const T& val = T()) { create(n, val); }

	size_type size() const { return limit - data; }
	
	T& operator[] (size_type i) { return data[i]; }
	const T& operator[] (size_type i) const { return data[i]; }

private:
	//implementation
	iterator data; 	// first element in Vec
	iterator limit;	// one past the last element  in Vec

};
