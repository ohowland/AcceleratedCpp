#include "Str2.h"
#include <iostream>

int main() 
{
    Str s("hey mang.");
    std::cout << "START: MAIN API CALL" << std::endl;
    
    const char* tmp = s.c_str();
    std::cout << tmp << std::endl;
  
    std::cout << "NEW LINE PLEASE: ";
    Str s2;
    while(std::cin>>s2)
        ;
    
    const char* tmp2 = s2.data();
    std::cout << tmp2 << std::endl;
    std::cout << "END: MAIN API CALL" << std::endl;

    return 0;
}
