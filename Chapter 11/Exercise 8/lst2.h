#ifndef GUARD_LST_H_
#define GUARD_LST_H_

#include <memory>
#include <algorithm>
#include <cstddef>

template <class T> class lst {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;

    lst() { create(0); } // constructor
    lst(const lst& l) { clone(l.data, l.avail); } // copy constructor
    lst(const_iterator b, const_iterator e) { clone(b,e); }
    lst& operator=(const lst&); // assignment operator
    ~lst() { uncreate(); } // destructor!

    const_iterator begin() const { return data; }
    const_iterator end() const { return avail; }

private:
    iterator data;
    iterator avail;
    std::allocator<value_type> alloc;

    void clone(const_iterator, const_iterator);
    void create(size_type);
    void uncreate();

};

// public
template <class T>
lst<T> append(const lst<T>&, const lst<T>&);

template <class T>
lst<T>& lst<T>::operator=(const lst<T>& other) {
    if (this != &other) {
        // handle self assignment.
        uncreate();
        clone(other.data, other.avail);
    }
    return *this;
}

// private
template <class T>
void lst<T>::clone(const_iterator b, const_iterator e) {
    create(b - e);
    uninitialized_copy(b, e, data);
}

template <class T>
void lst<T>::uncreate() {
    if (data) {
        for (iterator iter = data; iter != avail; ++iter)
            alloc.destroy(iter);
        alloc.deallocate(data, avail - data);
    }

    data = avail = 0;
}

template <class T>
void lst<T>::create(size_type n) {
    data = alloc.allocate(n);
    avail = data + n;
}

#endif
