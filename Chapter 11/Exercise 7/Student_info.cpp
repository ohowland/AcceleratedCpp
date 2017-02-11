#include "Student_info.h"

void Student_info::print(const std::string& s)
{
    std::cout << s << std::endl;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

std::istream& read(std::istream& in, Student_info& s)
{
	in >> s.name >> s.midterm >> s.final;
	read_hw(in, s.homework);
	return in;
}

std::istream& read_hw(std::istream& in, Vec<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);
		
		in.clear();
	}

	return in;
}
