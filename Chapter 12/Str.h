#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include "Vec.h"

class Str {
public:
    typedef Vec<char>::size_type size_type;
    
    // Default Constructor
    Str() { } 

    // Construct Str containing n copies of c
    Str(size_type n, char c): data(n, c) { }

    // Construct Str from null-terminated array of char
    Str(const char* cp) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }

    // Construct Str from the range denoted by iterators
    template <class In>
    Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

private:
    Vec<char> data;
}

#endif
