#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <cctype>
#include <cstring>
#include <iostream>

class Str {

friend std::istream& operator>>(std::istream&, Str&);

public:
    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(),
                  std::back_inserter(data));
        return *this;
    }
    
    typedef size_t size_type;

    /* Default Constructor */
    Str() { create(); } 
    
    /* Construct Str containing n copies of c */
    // Str(size_type n, char c) { }
    
    /* Construct Str from null-terminated array of char */
    // Str(const char* cp) { std::copy(cp, cp + std::strlen(cp), std::back_inserter(data)); }
    
    /* Construct Str from the range denoted by iterators */
    // template <class In>
    // Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }

    /* Copy Constructor */
    Str(const Str& a) { create(a.data, a.len); }

    /* Assignment Operator */
    Str& operator=(const Str&);

    /* Destructor */
    ~Str() { uncreate(); };

    /* from vec:
	Vec(const Vec& v) { create(v.begin(), v.end()); } // copy constructor T::T(const T&)
	Vec& operator=(const Vec&); // assignment operator T::operator=(const T&)
	~Vec() { uncreate(); } // destructor T::~T(V)
    */

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    size_type size() const { return len; }

private:
    char* data;
    size_type len;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

std::istream& operator>>(std::istream& is, Str& s)
{
    // remove existing value(s)
    s.data.clear();

    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ;    // do nothing except test condition.
    // read until next whitespace character
    if (is) {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c)); 
        // if whitespace is read, put it back on the stream.
        if (is)
            is.unget();
    }

    return is;
}

Str operator+(const Str& s, const Str& t)
{
    Str r = s;
    r += t;
    return r;
}

#endif
