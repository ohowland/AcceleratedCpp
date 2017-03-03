#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>

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


/* --------------- 12.3 --------------- */
inline bool operator>(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) > 0);
}

inline bool operator<(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) < 0);
}

/* --------------- 12.4 --------------- */
inline bool operator==(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) == 0);
}

inline bool operator!=(const Str& s, const Str& t)
{
    return (strcmp(s.c_str(), t.c_str()) != 0);
}

Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*);
Str operator+(const char*, const Str&);

/* --------------- 12.8 --------------- */
std::istream& operator>>(std::istream&, Str&);

std::istream& getline(std::istream&, Str&);

/* --------------- 12.9 --------------- */
std::ostream& operator<<(std::ostream&, const Str&);

std::ostream_iterator<char>& operator<<(std::ostream_iterator<char>&, const Str&);

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

#endif
