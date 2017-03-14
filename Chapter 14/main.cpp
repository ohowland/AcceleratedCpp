#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

#include "Student_info.hpp"

int main()
{
    std::vector< Handle<Core> > students;
    Handle<Core> record;
    char ch;
    std::string::size_type maxlen = 0;

    while (std::cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(std::cin);
        maxlen = std::max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_Core_handles);

    for (std::vector< Handle<Core> >::size_type i = 0;
         i != students.size(); ++i) {
        std::cout << students[i]->name()
                  << std::string(maxlen + 1 - students[i]->name().size(), ' ');
        try {
            double final_grade = students[i]->grade();
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
                      << std::setprecision(prec) << std::endl;
        } catch (std::domain_error e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}

