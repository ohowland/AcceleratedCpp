#include "Str.hpp"

#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>

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

/* --------------- 12.5 --------------- */ 
Str& Str::operator+=(const Str& s)
{
    size_type new_len = len_ + s.size();
    iterator new_data = alloc.allocate(new_len);
    std::uninitialized_copy(data_, data_ + len_ - 1, new_data);
    std::uninitialized_copy(s.begin(), s.end(), new_data + len_ - 1);
    alloc.construct(new_data + new_len - 1, '\0');
 
    uncreate();

    data_ = new_data;
    len_ = new_len;

    return *this;
}


/* --------------- 12.8 --------------- */
int is_new_line(int c) { return (c == '\n'); }

std::istream& read_until(std::istream& in, Str& s, int is_stop_char(int))
{
    std::vector<char> temp;
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

/* --------------- 12.11 --------------- */ 
Str operator+(const Str& s, const Str& t)
{
    std::cout << "CALLED ADDITION OP" << std::endl;
    Str r = s;
    r += t;
    std::cout << ">> " << r.c_str() << std::endl;
    return r;
}

Str operator+(const Str& s, const char* t)
{
    std::cout << "CALLED ADDITION OP" << std::endl;
    Str r = s;
    r += Str(t, t + strlen(t));
    std::cout << ">> " << r.c_str() << std::endl;
    return r;
}

Str operator+(const char* s, const Str& t)
{
    std::cout << "CALLED ADDITION OP" << std::endl;
    Str r = Str(s, s + strlen(s));
    r += t; 
    std::cout << ">> " << r.c_str() << std::endl;
    return r;
}

Str Str::substr(size_type pos, size_type len) const {
    return Str(data_ + pos, data_ + pos + len);
}

/* -------------- 12.13 --------------- */ 
Str& Str::operator=(const Str& rhs)
{
    if (&rhs == this) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    
    return *this; 
}
