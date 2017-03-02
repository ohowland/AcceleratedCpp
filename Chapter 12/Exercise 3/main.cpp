#include "Str2.h"
#include <iostream>

int main() 
{
    Str s("hey mang.");
    Str s2("hey mang.");
    Str s3("aa");
    Str s4("zz");
    std::cout << "START: MAIN API CALL" << std::endl;
    
    std::cout << (s==s2) << (s==s3) << (s!=s3) 
              << (s3>s4) << (s3<s4) << std::endl;
 
    Str t;
    getline(std::cin, t);

    std::cout << t.c_str() << std::endl;

    std::cout << "END: MAIN API CALL" << std::endl;

    return 0;
}
