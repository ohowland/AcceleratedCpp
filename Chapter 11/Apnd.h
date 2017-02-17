#ifndef GUARD_TMP_APND_H_
#define GUARD_TMP_APND_H_

#include <memory>
#include <cstddef>
#include <iostream>

template <class T> class Apnd {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    // default constructor
    Apnd() { create();  }
    
    // copy constructor
    Apnd(const Apnd& a) { create(a.begin(), a.end()); }

    // assignment operator
    Apnd& operator=(const Apnd&);

    // destructor
    ~Apnd() { uncreate(); }

    void push_back(const T& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }

    iterator begin() { return data; }
    const_iterator begin() const {return data; }

    iterator end() { return avail; }
    const_iterator end() const {return avail; }

    void regurge();

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<T> alloc;
    
    void create();
    void create(const_iterator, const_iterator);
    
    void uncreate();

    void grow();
    void unchecked_append(const T&);
};

template <class T>
void Apnd<T>::regurge()
{
    std::cout << std::endl;
    for(iterator it = data; it != avail; it++)
        std::cout << *it;
    std::cout << std::endl;
}

template <class T>
void Apnd<T>::create()
{
    data = avail = limit = 0;
}

template <class T>
void Apnd<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Apnd<T>::uncreate()
{
    if (data) {
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        alloc.deallocate(data, limit-data);
    }
    data = limit = avail = 0;
}

template <class T>
Apnd<T>& Apnd<T>::operator=(const Apnd& rhs)
{
    if (&rhs != this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Apnd<T>::grow()
{
    size_type new_size = std::max(2 * (limit-data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Apnd<T>::unchecked_append(const T& t)
{
    alloc.construct(avail++, t);
}

#endif
