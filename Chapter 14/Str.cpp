#include "Str.hpp"

#include <cctype>
#include <iostream>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

Str operator+(const Str& s, const Str& t)
{
    Str r = s;
    r += t;
    return r;
}
