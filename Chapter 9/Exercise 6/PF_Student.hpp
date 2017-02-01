#ifndef PF_Student_h
#define PF_Student_h

#include <string>
#include <vector>
#include <istream>

class Student_info {
public:
	Student_info();
	Student_info(std::istream&);
	
	std::istream& read(std::istream&);

	std::string name() const {return _name; }
	bool pass() const {return _pass; }

private:
	double midterm, final;
	std::string _name;
	bool _pass;

};

bool compare(const Student_info&, const Student_info&);
bool compare_two(const Student_info&);
bool fail(double);

#endif
