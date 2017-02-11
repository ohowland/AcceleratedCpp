#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "Vec.h"
#include "grade.h"
#include "Student_info.h"

int main()
{
    Vec<Student_info> students;
	Student_info record;
    std::string::size_type maxlen = 0;

	// read and store the data

    while (read(std::cin, record)) {
		maxlen = std::max(maxlen, record.name.size());
		students.push_back(record);
	}

    std::sort(students.begin(), students.end(), compare);

	for (Vec<Student_info>::size_type i = 0;
		 i != students.size(); ++i) {
        std::cout << students[i].name
			 << std::string(maxlen + 1 - students[i].name.size(), ' ');
		try {
			double final_grade = grade(students[i]);
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
				 << std::setprecision(prec) << std::endl;;
		} catch (std::domain_error e) {
            std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

	
