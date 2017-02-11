#ifndef GUARD_VEC_H_
#define GUARD_VEC_H_

#include <memory>
#include <algorithm>
#include <cstddef>

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;	

	// always need constructor, destructor, copy and assignmnet.
	// rule of three: if you need one you need the other
	// destructor, copy, assignment.
	
	Vec() { create(); } // constructor T::T()
	explicit Vec(std::size_t n, const T& t = T()) { create(n, t); }
	Vec(const Vec& v) { create(v.begin(), v.end()); } // copy constructor T::T(const T&)
	Vec& operator=(const Vec&); // assignment operator T::operator=(const T&)
	~Vec() { uncreate(); } // destructor T::~T(V)
	
	T& operator[] (size_type i) { return data[i]; }
	const T& operator[] (size_type i) const { return data[i]; }

	void push_back(const T& t) {
		if (avail == limit) // get space if needed
			grow();
		unchecked_append(t); // append the new element
	}
	
	size_type size() const { return avail - data; }

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

    iterator erase(iterator pos) {
        for(iterator iter = pos; iter != avail; ++iter) {
           alloc.destroy(iter); // Destroys the element object pointed to without deallocating its storage.
           if ((iter + 1) != avail)
               alloc.construct(iter, *(iter + 1)); // at pointer constructs arguments
        }
        avail--;
        return pos;
    }

    void clear() { uncreate(); }

private:
	//implementation
	iterator data; 	// first element in Vec
	iterator avail;	// pointer to (one past) the last constructed element
	iterator limit;	// one past the last available element

	// facilities for memory allocation
	std::allocator<T> alloc;

	// allocate and initalize the underlying array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// destry the elements in the array and free memory
	void uncreate();

	// support functions for push_back
	void grow();
	void unchecked_append(const T&);
};

template <class T>
void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate()
{
	if (data) {
		// destroy (in reverse order) the elements that were constructed
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// return all the space that was allocated
		alloc.deallocate(data, limit - data);
	}
	// reset pointers to indicate that the vec is empty again
	data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow()
{
	// when growing, allocate twice as much space as currently in use
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

	// allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// return the old space
	uncreate();

	// reset pointers to point to newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// assumes avail points to allocated, but unintialized space
template <class T>
void Vec<T>::unchecked_append(const T& t)
{
	alloc.construct(avail++, t);
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// check for self assignment
	if (&rhs != this) {
		// free the array in the left-hand side
		uncreate();

		// copy elements from the right-hand to the left-hand side
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

#endif
