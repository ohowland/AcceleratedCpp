#ifndef GUARD_REF_HANDLE_HPP_
#define GUARD_REF_HANDLE_HPP_

#include <ctypes>
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
        throw std::runtime_error("unbound Ref_hadnle");
    }

private:
    T* p;
    std::size_t* refptr;
};

#endif
