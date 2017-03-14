#include "Ptr.hpp"
#include <vector>

template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
    ++*rhs.refptr;
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T> Ptr<T>::~Ptr()
{
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

template <class T> T* clone(const T* tp)
{
    return tp->clone();
}

template<>
std::vector<char>* clone(const std::vector<char>* vp)
{
    return new std::vector<char>(*vp);
}
