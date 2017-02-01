#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <vector>
#include <istream>

class Student_info {
public:
	// constructors
	Student_info(); // the 'default constructor' 
	Student_info(std::istream&); // initalized s2 by reading from cin
	
	// interface goes here
	std::istream& read(std::istream&);
	
	// this accessor is a member function defined 
	// as part of the class definition.
	// we're telling compiler that it hsould avoid function-call overhead
	// and expand calls to the function inline if possible
	std::string name() const { return n; }
	double grade() const { return course_grade; }	
	bool valid() const { return !homework.empty(); }

private:
	// implementation goes here
	std::string n;
	double midterm, final, course_grade;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
