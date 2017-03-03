#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <cctype>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>
#include <algorithm>
#include <cstddef>
#include "Vec.hpp" 

class Str {


public:
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef size_t size_type;
    typedef char value_type;
    typedef std::ptrdiff_t difference_type;
    typedef char& reference;
    typedef const char& const_reference;

/* --------------- 12.1 --------------- */
    /* Constructors */
    Str() { create(0, '\0'); } 
    Str(size_type n, char c) { create(n, c); }
    Str(const char* cp) { create(cp, cp + strlen(cp)); }
    template <class In> Str(In i, In j) { create(i, j); }

    /* Copy Constructor */
    Str(const Str& a) { create(a.begin(), a.end()); }
    
    Str& operator=(const Str&);
    ~Str() { uncreate(); };


    reference operator[](size_type i) { return data_[i]; }
    const_reference operator[](size_type i) const { return data_[i]; }

    size_type size() const { return len_ - 1; }

    Str& operator+=(const Str&);
    Str& operator+=(const_iterator);

/* --------------- 12.2 --------------- */
    const char* c_str() const {
        std::cout << "CALLED: C_STR" << std::endl;
        return data_;
    }
    const char* data() const {
        std::cout << "CALLED: DATA" << std::endl;
        return data_;
    }
    size_type copy(iterator, size_type, size_type);

/* --------------- 12.6 --------------- */
    operator bool() { return size() > 0; }

/* --------------- 12.7 --------------- */
    iterator begin() { return data_; }
    const_iterator begin() const { return data_; }

    iterator end() { return data_ + len_ - 1; }
    const_iterator end() const { return data_ + len_ - 1; }

/* --------------- 12.11 --------------- */
    Str substr(size_type, size_type) const;

/* --------------- 12.12 --------------- */
    template <class In> void insert(iterator, In, In);
    
private:
    size_type len_;
    iterator data_;

    std::allocator<char> alloc;

    void create(size_type, char);
    template <class In> void create(In, In);
    void uncreate();
};

/* --------------- 12.1 --------------- */  
void Str::create(size_type l, char c)
{
    std::cout << "CALLED: CREATE OBJ (default)" << std::endl;
    len_ = l + 1;
    data_ = alloc.allocate(len_);
    std::uninitialized_fill(data_, data_ + len_ - 1, c);
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
    
    data_ = 0;
    len_ = 0;
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


/* --------------- 12.2 --------------- */ 
Str::size_type Str::copy(iterator p, size_type len, size_type pos)
{
    if (pos > size())
        throw std::out_of_range("pos > size()");
    size_type copy_len = std::min(len, size() - pos);
    std::copy(data_ + pos, data_ + copy_len, p);
    return copy_len;
}


/* --------------- 12.3 --------------- */
bool operator>(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) > 0);
}

bool operator<(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) < 0);
}

/* --------------- 12.4 --------------- */
bool operator==(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) == 0);
}

bool operator!=(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) != 0);
}

/* --------------- 12.5 --------------- */  
Str& Str::operator+=(const Str& s)
{
    size_type new_len = len_ + s.size();
    iterator new_data = alloc.allocate(new_len);
    std::uninitialized_copy(data_, data_ + len_, new_data);
    std::uninitialized_copy(s.begin(), s.end(), new_data + len_);
    alloc.construct(new_data + new_len - 1, '\0');
 
    uncreate();

    data_ = new_data;
    len_ = new_len;

    return *this;
}

Str operator+(const Str& s, const Str& t)
{
    std::cout << "CALLED ADDITION OP" << std::endl;
    Str r = s;
    r += t;
    return r;
}

/* --------------- 12.8 --------------- */
int is_new_line(int c) { return (c == '\n'); }

std::istream& read_until(std::istream& in, Str& s, int is_stop_char(int))
{
    Vec<char> temp;
    char c;
    
    while (in.get(c) && isspace(c))
        ;
    if (in) {
        do temp.push_back(c);
        while (in.get(c) && !is_stop_char(c));
        if (in) in.unget();
    }

    s = Str(temp.begin(), temp.end());
    return in;
}

std::istream& operator>>(std::istream& in, Str& s)
{
    std::cout << "CALLED: IN STREAM" << std::endl;
    return read_until(in, s, isspace);
} 

std::istream& getline(std::istream& in, Str& s)
{
    std::cout << "CALLED: GETLINE" << std::endl;
    return read_until(in, s, is_new_line);
}

/* --------------- 12.9 --------------- */
std::ostream& operator<<(std::ostream& os, const Str& s)
{
    std::cout << "CALLED: OUT STREAM" << std::endl;
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

std::ostream_iterator<char>& operator<<(std::ostream_iterator<char>& osi, const Str& s) {
    copy(s.begin(), s.end(), osi);
    return osi;
}

/* --------------- 12.10 --------------- */  
template <class In>
void Str::create(In i, In j)
{
    std::cout << "CALLED: CREATE OBJ (by iterator)" << std::endl;
    len_ = j - i + 1;
    data_ = alloc.allocate(len_);
    std::uninitialized_copy(i, j, data_);
    alloc.construct(data_ + len_ - 1, '\0');
}

/* -------------- 12.12 --------------- */ 
Str Str::substr(size_type pos, size_type len) const {
    return Str(data_ + pos, data_ + pos + len);
}

/* -------------- 12.12 --------------- */ 
template <class In> void Str::insert(iterator p, In i, In j) {
    size_type new_len = len_ + (j - i);
    iterator new_data = alloc.allocate(new_len);
    std::uninitialized_copy(data_, p, new_data);
    std::uninitialized_copy(i, j, new_data + (p - data_));
    std::uninitialized_copy(p, data_ + len_ - 1, new_data + (p - data_) + (j - i));
    alloc.construct(new_data + new_len - 1, '\0');
   
    uncreate();

    data_ = new_data;
    len_ = new_len;
}

/* -------------- 12.13 --------------- */ 


#endif
