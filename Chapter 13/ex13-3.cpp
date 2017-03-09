#include <string>
#include <iostream>

#include "Student_info.hpp"

int main()
{
    std::string tmp;

    Core c(std::cin);
    tmp = c.valid() == 1 ? "VALID" : "INVALID";
    std::cout << tmp << std::endl;

    Grad g(std::cin);
    tmp = g.valid() == 1 ? "VALID" : "INVALID";
    std::cout << tmp << std::endl;

    Student_info s(std::cin);
    tmp = s.valid() == 1 ? "VALID" : "INVALID";
    std::cout << tmp << std::endl;

    return 0;
}
