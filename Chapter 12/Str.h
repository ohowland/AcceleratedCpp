#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <iostream>
#include <cstddef>
#include "Vec.h"

class Str {
    friend std::istream& operator>>(std::istream&, Str&);

public:
    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }

    typedef Vec<char>::size_type size_type;

    // Default Constructor
    Str() { } 

    // Construct Str containing n copies of c
    Str(size_type n, char c): data(n, c) { }

    // Construct Str from null-terminated array of char
    Str(const char* cp) {
        std::copy(cp, cp + strlen(cp), std::back_inserter(data));
    }

    // Construct Str from the range denoted by iterators
    template <class In>
    Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    size_type size() const { return data.size(); }

private:
    Vec<char> data;
};

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

std::istream& operator>>(std::istream& is, Str& s)
{
    s.data.clear();
    
    char c;
    while(is.get(c) && isspace(c))
        ;
    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        if (is)
            is.unget();
    }
    return is;
}

#endif
