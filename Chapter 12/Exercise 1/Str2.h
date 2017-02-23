#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <cctype>
#include <cstring>
#include <iostream>
#include <memory>
#include <algorithm>
#include <cstddef>

class Str {

public:
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef size_t size_type;
    typedef char value_type;
    typedef std::ptrdiff_t difference_type;
    typedef char& reference;
    typedef const char& const_reference;

    /* Constructors */
    Str() { create(0, '\0'); } 
    Str(size_type n, char c) { create(n, c); }
    Str(const char* cp) { create(cp, cp + strlen(cp)); }
    template <class In> Str(In i, In j) { create(i, j); }

    /* Copy Constructor */
    Str(const Str& a) { create(a.begin(), a.end()); }
    
    Str& operator=(const Str&);
    ~Str() { uncreate(); };

    iterator begin() { return data_; }
    const_iterator begin() const { return data_; }

    iterator end() { return data_ + len_ - 1; }
    const_iterator end() const { return data_ + len_ - 1; }

    reference operator[](size_type i) { return data_[i]; }
    const_reference operator[](size_type i) const { return data_[i]; }

    size_type size() const { return len_ - 1; }

    Str& operator+=(const Str&);
    template <class In> void insert(iterator, In, In);

private:
    size_type len_;
    iterator data_;

    std::allocator<char> alloc;

    void create(size_type, char);
    template <class In> void create(In, In);
    void uncreate();

    void grow(size_type);
};

template <class In> void Str::insert(iterator p, In i, In j) {
    size_type new_len = len_ + (j - i);
    iterator new_data = alloc.allocate(new_len);
    uninitialized_copy(data_, p, new_data);
    uninitialized_copy(i, j, new_data + (p - data_));
uninitialized_copy

void Str::create(size_type l, char c)
{
    std::cout << "CALLED: CREATE OBJ (default)" << std::endl;
    len_ = l + 1;
    data_ = alloc.allocate(len_);
    std::uninitialized_fill(data_, data_ + len_ - 1, c);
    alloc.construct(data_ + len_ - 1, '\0');
}

template <class In>
void Str::create(In i, In j)
{
    std::cout << "CALLED: CREATE OBJ (by iterator)" << std::endl;
    len_ = j - i + 1;
    data_ = alloc.allocate(len_);
    std::uninitialized_copy(i, j, data_);
    alloc.construct(data_ + len_ - 1, '\0');
}

void Str::uncreate()
{
    std::cout << "CALLED: UNCREATE OBJ" << std::endl;
    if (data_) {
        iterator it = data_ + len_;
        while (it != data_)
            alloc.destroy(--it);
        alloc.deallocate(data_, len_);
    }
    
    data_ = nullptr;
    len_ = 0;
}

void Str::grow()
{
    std::cout << "CALLED: GROW OBJ ";
    size_type new_len = std::max(2 * len_, size_t(1));
    std::cout << "(NEW SIZE: " << new_len << ")" << std::endl;
    iterator new_data = alloc.allocate(new_len);
    std::uninitialized_copy(data_, data_ + len_ - 1, new_data);

    uncreate();

    data_ = new_data;
    std::cout << "DATA_: " << data_;
    len_ = new_len;
    std::cout << ", LEN_: " << len_ << std::endl;
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
    Str::value_type c;
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
