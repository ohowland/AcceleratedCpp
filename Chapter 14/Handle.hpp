#ifndef GUARD_HANDLE_HPP
#define GUARD_HANDLE_HPP

#include "Core.hpp"

template <class T> class Handle {
public:
    Handle(): p(0) { }
    Handle(const Handle& s): p(0) { if (s.p) p = s.p->clone(); }
    Handle& operator=(const Handle&);
    ~Handle() { delete p; }

    Handle(T* t): p(t) { }

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
};

template <class T>
bool compare_Core_handles(const Handle<T>&, const Handle<T>&);


#endif
