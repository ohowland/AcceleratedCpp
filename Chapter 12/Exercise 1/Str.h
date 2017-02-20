#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <cctype>
#include <cstring>
#include <iostream>
#include <memory>
#include <algorithm>
#include <cstddef>

class Str {

friend std::istream& operator>>(std::istream&, Str&);

public:
    Str& operator+=(const Str& s) {
        std::copy(s.begin(), s.end(), std::back_inserter(*this));
        return *this;
    }
    
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef size_t size_type;
    typedef char value_type;
    typedef std::ptrdiff_t difference_type;
    typedef char& reference;
    typedef const char& const_reference;

    /* Constructors */
    /* Default */
    Str() { create(); } 

    /* From null terminated String */
    Str(const char* cp) {
        create();
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(*this));
    }

    /* From iterators */
    Str(const_iterator b, const_iterator e) { create(b,e); }

    void push_back(const char& c) {
        std::cout << "CALLED: PUSH BACK" << std::endl;; 
        if (avail == limit)
            grow();
        unchecked_append(c);
    }

    /* Copy Constructor */
    Str(const Str& a) { create(a.begin(), a.end()); }
    
    Str& operator=(const Str&);
    ~Str() { uncreate(); };

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    char& operator[](size_type i) { return *(data + i); }
    const char& operator[](size_type i) const { return *(data + i); }
    size_type size() const { return avail - data; }
    void clear() { uncreate(); }

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<char> alloc;

    void create();
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const char&);
};

void Str::create()
{
    std::cout << "CALLED: CREATE OBJ (default)" << std::endl;
    data = avail = limit = 0;
}

void Str::create(const_iterator i, const_iterator j)
{
    std::cout << "CALLED: CREATE OBJ (by iterator)" << std::endl;
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

void Str::uncreate()
{
    std::cout << "CALLED: UNCREATE OBJ" << std::endl;
    if (data) {
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

void Str::grow()
{
    std::cout << "CALLED: GROW OBJ ";
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    std::cout << "(NEW SIZE: " << new_size << ")" << std::endl;;
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    std::cout << "NEW_DATA: " << data;
    avail = new_avail;
    std::cout << ", NEW_AVAIL: " << avail - data; 
    limit = data + new_size;
    std::cout << ", NEW_LIMIT: " << limit - data << std::endl;
}

void Str::unchecked_append(const char& c)
{
    std::cout << "CALLED: UNCHECKED APPEND";
    std::cout << " (CHAR: " << c << ", AVAIL: " << avail
              << ")" << std::endl;
    alloc.construct(avail++, c);
}

Str& Str::operator=(const Str& rhs)
{
    std::cout << "CALLED: ASSIGN OP" << std::endl;
    if (&rhs != this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    std::cout << "CALLED: OUT STREAM" << std::endl;
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

std::istream& operator>>(std::istream& is, Str& s)
{
    std::cout << "CALLED: IN STREAM" << std::endl;
    
    // read and discard leading whitespace
    char c;
    is.get(c)
        ;
    if (is) {
        do s.push_back(c);
        while (is.get(c) && !isspace(c)); 
        // if whitespace is read, put it back on the stream.
        if (is)
            is.unget();
    }

    return is;
}


Str operator+(const Str& s, const Str& t)
{
    std::cout << "CALLED ADDITION OP" << std::endl;
    Str r = s;
    r += t;
    return r;
}

#endif
