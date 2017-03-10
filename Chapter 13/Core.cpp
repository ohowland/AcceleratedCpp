#include "Core.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "grade.h"

using namespace std;

/* helpers */

bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}

bool fail(const double& grade)
{
    return grade < 60;
}

std::string letter_grade_conv(const double& grade)
{
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);  

    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i])
            return letters[i];
    }

    return "?\?\?";
}

/*---------------CORE---------------*/ 
string Core::name() const {
    //std::cerr << "Core::name()" << std::endl; 
    return n;
}

double Core::grade() const
{
    //std::cerr << "Core::grade()" << std::endl; 
    return ::grade(midterm, final, homework);
}

std::string Core::letter_grade()
{
    return letter_grade_conv(grade());
}

std::istream& Core::read_common(std::istream& in)
{
    //std::cerr << "Core::read_common()" << std::endl; 
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read_hw(istream& in, vector<double>& hw)
{
    //std::cerr << "Core::read_hw()" << std::endl; 
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

istream& Core::read(istream& in)
{
    //std::cerr << "Core::read()" << std::endl; 
    read_common(in);
    read_hw(in, homework);
    return in;
}

bool Core::met_requirements() const
{
    return !homework.empty();
}

/*---------------GRAD---------------*/ 
double Grad::grade() const
{
    //std::cerr << "Grad::grade()" << std::endl; 
    return min(Core::grade(), thesis);
}

istream& Grad::read(istream& in)
{
    //std::cerr << "Grad::read()" << std::endl; 
    Core::read_common(in);
    in >> thesis;
    read_hw(in, Core::homework);
    return in;
}

bool Grad::met_requirements() const
{
    return Core::met_requirements() && thesis != 0;
}

/*---------------PASS---------------*/ 
double Pass::grade() const
{    
    //std::cerr << "Pass::grade()" << std::endl;
    double final_grade;
    if (homework.empty())
        final_grade = ::grade(midterm, final);
    else
        final_grade = Core::grade();
    
    return final_grade;
}

istream& Pass::read(istream& in)
{
    //std::cerr << " Pass::read()" << std::endl;
    Core::read_common(in);
    read_hw(in, Core::homework);
    return in;
}

std::string Pass::letter_grade()
{
    return fail(grade()) ? "FAIL" : "PASS";
}

/*---------------AUDIT---------------*/

std::string Audit::letter_grade()
{
    return "AUDIT";
}

