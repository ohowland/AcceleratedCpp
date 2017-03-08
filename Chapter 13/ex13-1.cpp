#include <string>
#include <iostream>

#include "Core.hpp"

int main()
{
    std::cout << "--------------- C1 ---------------" << std::endl;
    // ::Core()
    Core c1;

    std::cout << "--------------- C2 ---------------" << std::endl;
    // ::Core(istream&)
    Core c2(std::cin);

    std::cout << "--------------- G1 ---------------" << std::endl;
    // ::Core()
    // ::Grad()
    Grad g1;

    std::cout << "--------------- G2 ---------------" << std::endl;
    // ::Core()
    // ::Grad(istream&)
    Grad g2(std::cin);

    return 0;
}
