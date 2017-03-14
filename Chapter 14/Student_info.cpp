#include "Student_info.hpp"

#include <iostream>


std::istream& Student_info::read(std::istream& is)
{
    char ch;
    is >> ch;

    // allocate new object of the appropriate type
    if (ch == 'U')
        cp = new Core(is);
    else
        cp = new Grad(is);

    return is;
}
