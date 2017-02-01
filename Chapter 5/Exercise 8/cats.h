#ifndef GUARD_cats_h
#define GUARD_cats_h

#include <vector>
#include <string>

std::vector<std::string> 
vcat(const std::vector<std::string>&, const std::vector<std::string>&);

std::vector<std::string>
hcat(const std::vector<std::string>&, const std::vector<std::string>&);
#endif
