#ifndef GUARD_CORE_HPP_
#define GUARD_CORE_HPP_

#include <string>
#include <iostream>
#include <vector>

class Core {
    friend class Handle;
public:
    Core(): midterm(0), final(0) {
        //std::cerr << "Core::Core()" << std::endl;
        }
    Core(std::istream& is) { 
        //std::cerr << "Core::Core(istream&)" << std::endl;
        read(is);
    }

    virtual ~Core() { } 

    std::string name() const;
    bool valid() const { return !homework.empty(); }
    
    virtual std::istream& read(std::istream&);
    virtual double grade() const;
    virtual std::string letter_grade();
    virtual bool met_requirements() const;

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
    Grad(): thesis(0) {
        //std::cerr << "Grad::Grad()" << std::endl;
        }
    Grad(std::istream& is) { 
        //std::cerr << "Grad::Grad(istream&)" << std::endl;
        read(is);
    }
    
    double grade() const;
    std::istream& read(std::istream&);
    bool met_requirements() const;

protected:
    Grad* clone() const { return new Grad (*this); }

private:
    double thesis;
};

class Pass: public Core {
public:
    Pass() {
        //std::cerr << "Pass:Pass()" << std::endl;
        }
    Pass(std::istream& is) {
        //std::cerr << "Pass:Pass(istream&)" << std::endl;
        read(is);
    }
    
    double grade() const;
    std::istream& read(std::istream&);
    std::string letter_grade();

protected:
    Pass* clone() const { return new Pass (*this); }
};

class Audit: public Core {
public:
    Audit() { }
    Audit(std::istream& is) { read(is) };
   
    std::string letter_grade();
protected:
    Audit* clone() const { return new Audit (*this); }
};

bool compare(const Core&, const Core&);
bool fail(const double&);
std::string letter_grade_conv(const double&);

#endif
