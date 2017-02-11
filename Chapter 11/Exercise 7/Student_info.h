#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <iostream>
#include "Vec.h"

class Student_info {
public:
	// constructors
	Student_info() { print("create"); }  
    
    // copy constructor
    Student_info(const Student_info& other) {
        print("copy");
        clone(other);
    }

    // assignment operator
    Student_info& operator=(const Student_info& other) {
        print("assign");
        if (this != &other)
            clone(other);
        return *this;
    }

    // destructor
    ~Student_info() { print("destroy"); }

	// API 
    std::string name;
    double midterm, final;
    Vec<double> homework;

private:
	// implementation goes here
    void print(const std::string&);
	void clone(const Student_info& other) {
        name = other.name;
        midterm = other.midterm;
        final = other.final;
        homework = other.homework;
    }
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, Vec<double>&);
std::istream& read(std::istream&, Student_info&);
#endif
