#include "Str2.h"
#include <iostream>

int main() 
{
    Str s("hey ");

    Str s2 = "mang!!!";

    std::cout << "START: MAIN API CALL" << std::endl;
   
    s+=s2;

    std::cout << s << std::endl;

    std::cout << "END: MAIN API CALL" << std::endl;

    return 0;
}
