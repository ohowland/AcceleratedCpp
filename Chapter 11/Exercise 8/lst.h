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

    lst() { create(); } // constructor
    lst(const lst& l) { clone(l.head, l.tail) } // copy constructor
    lst(const_iterator b, const_iterator e) { clone(b,e); }
    lst& operator=(const lst&); // assignment operator
    ~lst() { uncreate(); } // destructor!

    size_type size() const {
        // TODO
        return 0;
    }

    iterator begin() { return head; }
    const_iterator begin() const { return head; }

    iterator end() { return tail; }
    const_iterator end() const { return tail; }

private:
    struct node {
        T data;
        node* next;
        node* prev;
    } root;

    iterator head;
    iterator tail;

    void create();
    void create(const node&)

    void uncreate();

};

template <class T>
void lst<T>::create() {
    root.data = T;
    root.prev = root.next = T*;
    
}

template <class T>
void lst<T>:uncreate() {;}



#endif
