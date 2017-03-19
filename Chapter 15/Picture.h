#include <vector>
#include <string>
#include <iostream>

#include "Ptr.hpp"
#include "Pic.h"

class Picture {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend Picture frame(const Picture&);
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const Picture&);

public:
    Picture(const std::vector<std::string>& =
            std::vector<std::string>());

private:
    Ptr<Pic_base> p;
    Picture(Pic_base* ptr): p(ptr) { }
};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

