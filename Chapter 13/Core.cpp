#include "Core.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "grade.h"

using namespace std;

/*---------------CORE---------------*/ 
string Core::name() const {
    std::cerr << "Core::name()" << std::endl; 
    return n;
}

double Core::grade() const
{
    std::cerr << "Core::grade()" << std::endl; 
    return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in)
{
    std::cerr << "Core::read_common()" << std::endl; 
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read_hw(istream& in, vector<double>& hw)
{
    std::cerr << "Core::read_hw()" << std::endl; 
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

istream& Core::read(istream& in)
{
    std::cerr << "Core::read()" << std::endl; 
    read_common(in);
    read_hw(in, homework);
    return in;
}

bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}

/* UNUSED:
bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
    return compare(*cp1, *cp2);
}

bool compare_grades(const Core& c1, const Core& c2)
{
    return c1.grade() < c2.grade();
}*/

/*---------------GRAD---------------*/ 
double Grad::grade() const
{
    std::cerr << "Grad::grade()" << std::endl; 
    return min(Core::grade(), thesis);
}

istream& Grad::read(istream& in)
{
    std::cerr << "Grad::read()" << std::endl; 
    Core::read_common(in);
    in >> thesis;
    read_hw(in, Core::homework);
    return in;
}

