#ifndef GUARD_STR_H_
#define GUARD_STR_H_

#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>

#include "Ptr.hpp"
#include "Vec.hpp"

class Str {

public:
    typedef Vec<char>::size_type size_type;
    
    /* Constructors */
    Str(): data_(new Vec<char>) { } 
    
    Str(size_type n, char c): data_(new Vec<char>(n, c)) { }
    
    Str(const char* cp): data_(new Vec<char>) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data_));
    }

    template <class In> Str(In i, In j): data_(new Vec<char>) { 
        std::copy(i, j, std::back_inserter(*data_));
    }

    char& operator[](size_type i) {
        data_.make_unique();
        return (*data_)[i];
    }

    const char& operator[](size_type i) const { return (*data_)[i]; }

    size_type size() const { return data_->size(); }

    Str& operator+=(const Str& s) {
        data_.make_unique();
        std::copy(s.data_->begin(), s.data_->end(),
                  std::back_inserter(*data_));
        return *this;
    }

    typedef char* iterator;
    typedef const char* const_iterator;

    iterator begin() { return data_->begin(); }
    const_iterator begin() const { return data_->begin(); }

    char* end() { return data_->end(); }
    const_iterator end() const { return data_->end(); }

private:
    Ptr< Vec<char> > data_;
};

Str operator+(const Str&, const Str&);
std::ostream& operator<<(std::ostream&, const Str&);

#endif
