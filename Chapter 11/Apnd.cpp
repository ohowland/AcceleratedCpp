#include "Apnd.h"
#include <iostream>

int main()
{
    char s;
    Apnd<char> full_str;

    while(std::cin >> s)
        full_str.push_back(s);

    full_str.regurge();
    return 0;
}

