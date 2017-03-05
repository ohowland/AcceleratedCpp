#ifndef GUARD_CORE_HPP_
#define GUARD_CORE_HPP_

#include <string>
#include <iostream>
#include <vector>

class Core {
    friend class Student_info;
public:
    Core(): midterm(0), final(0) { }
    Core(std::istream& is) { read(is); } 
    virtual ~Core() { } 

    std::string name() const;
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
protected:
    virtual Core* clone() const { return new Core(*this); }
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;
private:
    std::string n;
};

class Grad: public Core {
public:
    Grad(): thesis(0) { }
    Grad(std::istream& is) { read(is); }

    double grade() const;
    std::istream& read(std::istream&);
protected:
    Grad* clone() const { return new Grad (*this); }
private:
    double thesis;
};

std::istream& Core::read_common(std::istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
bool compare_grades(const Core&, const Core&);

#endif
