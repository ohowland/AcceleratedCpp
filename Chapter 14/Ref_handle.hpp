#ifndef GUARD_REF_HANDLE_HPP_
#define GUARD_REF_HANDLE_HPP_

#include <stddef.h>
#include <stdexcept>

template <class T> class Ref_handle {
public:
    //manage reference count as well as pointer
    Ref_handle(): p(0), refptr(new std::size_t(1)) { }
    Ref_handle(T* t): p(t), refptr(new std::size_t(1)) { }
    Ref_handle(const Ref_handle& h): p(h.p), refptr(h.refptr) {
        ++*refptr;
    }

    Ref_handle& operator=(const Ref_handle&);
    ~Ref_handle();

    operator bool() const { return p; }
    T& operator*() const {
        if (p)
            return *p;
        throw std::runtime_error("unbound Ref_handle");
    }
    T* operator->() const {
        if (p)
            return p;
        throw std::runtime_error("unbound Ref_handle");
    }

private:
    T* p;
    std::size_t* refptr;
};
    
template <class T> Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
    // free the left-hand side, destroying pointers if appropriate
    ++*rhs.refptr;
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    // copy in values from the right-hand side
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T> Ref_handle<T>::~Ref_handle()
{
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

#endif
