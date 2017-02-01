#ifndef PF_Student_h
#define PF_Student_hpp

#include <string>
#include <vector>
#include <istream>

class Student_info {
public:
	Student_info();
	Student_info(std::istream&);
	
	std::istream& read(std::istream&);

	std::string name() const {return n; }
	char grade() const {return passfail; }

private:
	double midterm, final;
	std::string n;
	char passfail;

};

bool compare(const Student_info&, const Student_info&);
bool fail(double);

#endif
