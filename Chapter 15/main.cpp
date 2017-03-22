#include <string>
#include <vector>

#include "Pic.h"

int main() {
    std::vector<std::string> tmp;
    tmp.push_back("v v v");
    tmp.push_back("W O W");
    tmp.push_back("^ ^ ^");
    
    Picture p(tmp);  
    std::cout << p << std::endl;
    Picture q = frame(p);
    std::cout << q << std::endl;
    Picture r = hcat(q, p);
    std::cout << r << std::endl;
    Picture s = vcat(q, r);
    std::cout << s << std::endl;
    std::cout << frame(hcat(s, vcat(r,q))) << std::endl;
}
