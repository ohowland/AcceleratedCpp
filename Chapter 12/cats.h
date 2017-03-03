#ifndef GUARD_cats_h
#define GUARD_cats_h

#include <vector>
#include "Str.hpp" 

std::vector<Str> 
vcat(const std::vector<Str>&, const std::vector<Str>&);

std::vector<Str>
hcat(const std::vector<Str>&, const std::vector<Str>&);

#endif
