#include "Str.h"
#include <iostream>

int main() 
{
    Str s;
    std::cout << "START: MAIN API CALL" << std::endl;
    while(std::cin >> s)
        ;
    std::cout << "END: MAIN API CALL" << std::endl;

    std::cout << s <<  "LOOP COMPLETE" << std::endl;
    return 0;
}
