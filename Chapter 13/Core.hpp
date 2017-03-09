#ifndef GUARD_CORE_HPP_
#define GUARD_CORE_HPP_

#include <string>
#include <iostream>
#include <vector>

class Core {
    friend class Student_info;
public:
    Core(): midterm(0), final(0) { std::cerr << "Core::Core()" << std::endl;  }
    Core(std::istream& is) { 
        std::cerr << "Core::Core(istream&)" << std::endl;
        read(is);
    }

    virtual ~Core() { } 

    std::string name() const;
    bool valid() const { return !homework.empty(); }
    std::string letter_grade(const double&);

    virtual std::istream& read(std::istream&);
    virtual double grade() const;

protected:
    virtual Core* clone() const { return new Core(*this); }
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
    std::istream& read_hw(std::istream&, std::vector<double>&);

private:
    std::string n;
};

class Grad: public Core {
public:
    Grad(): thesis(0) { std::cerr << "Grad::Grad()" << std::endl; }
    Grad(std::istream& is) { 
        std::cerr << "Grad::Grad(istream&)" << std::endl;
        read(is);
    }
    
    double grade() const;
    std::istream& read(std::istream&);

protected:
    Grad* clone() const { return new Grad (*this); }

private:
    double thesis;
};

bool compare(const Core&, const Core&);
// bool compare_Core_ptrs(const Core*, const Core*);
// bool compare_grades(const Core&, const Core&);

#endif
