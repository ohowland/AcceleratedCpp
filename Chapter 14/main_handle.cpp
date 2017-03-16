#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

#include "Handle.hpp"
#include "Student_info.hpp"

bool compare_Core_handles(const Handle<Core>& lhs, const Handle<Core>& rhs) {
    return compare(*lhs, *rhs);
}

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

    std::sort(students.begin(), students.end(), compare_Core_handles);

    for (std::vector< Ptr<Core> >::size_type i = 0;
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

