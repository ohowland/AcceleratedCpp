#include "Str.h"
#include <iostream>

int main() 
{
    Str s("hey mang.");
    char* tmp;
    std::cout << "START: MAIN API CALL" << std::endl;
    
    tmp = s.c_str();
    std::cout << tmp << std::endl;
  
    s = "ya ya ya";

    tmp = s.data();
    std::cout << tmp << std::endl;

    std::cout << "END: MAIN API CALL" << std::endl;

    return 0;
}
