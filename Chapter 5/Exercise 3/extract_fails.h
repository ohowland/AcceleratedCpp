#ifndef GUARD_extract_fails_h
#define GUARD_extract_fails_h

#include <list>
#include <vector>
#include "Student_info.h"

std::vector<Student_info> extract_fails(std::vector<Student_info>& students);
std::list<Student_info> extract_fails(std::list<Student_info>& students);
#endif
