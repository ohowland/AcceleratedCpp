#ifndef GUARD_STUDENT_INFO_HPP_
#define GUARD_STUDENT_INFO_HPP_

#include <string>
#include <stdexcept>

#include "Handle.hpp"

class Student_info {
public:
    Student_info() { }
    Student_info(std::istream& is) { read(is) }
    // no copy, assign, or destructor!
    // this is a pure interface class.
    
    std::istream& read(std::istream&);
    
    std::string name() const {
        if (cp) return cp->name();
        else throw std::runtime_error("uninitalized Student");
    }

    double grade() const {
        if (cp) return cp->grade();
        else throw std::runtime_error("uninitalized Student");
    }

    static bool compare(const Student_info& s1,
                        const Student_info& s2) {
        return s1.name() < s2.name();
    }
private:
    Handle<Core> cp;
};

#endif
