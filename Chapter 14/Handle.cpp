#include "Handle.hpp"
#include <stdexcept>

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
    if (&rhs != this) {
        delete p;
        p = rhs.p ? rhs.p->clone() : 0;
    }
    return *this;
}

template <class T>
T& Handle<T>::operator*() const
{
    if (p)
        return *p;
    throw std::runtime_error("unbound Handle");
}

template <class T>
T* Handle<T>::operator->() const
{
    if (p)
        return p;
    throw std::runtime_error("unbound Handle");
}
