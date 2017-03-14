#ifndef GUARD_PTR_HPP_
#define GUARD_PTR_HPP_

#include <stddef.h>

template <class T> class Ptr {
public:
    // new member to copy the object conditionally when needed
    void make_unique() {
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? clone(p) : 0;
        }
    }

    Ptr(): p(0), refptr(new size_t(1)) { };
    Ptr(T* t): p(t), refptr(new size_t(1)) { };
    Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }

    Ptr& operator=(const Ptr&);
    ~Ptr();
    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
    size_t* refptr;
};

template <class T> T* clone(const T*);

#endif
