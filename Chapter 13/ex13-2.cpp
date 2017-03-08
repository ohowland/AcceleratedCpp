#include <string>
#include <iostream>

#include "Core.hpp"

int main()
{
    std::cerr << " ---------- p1 ---------- " << std::endl;
    // Core::Core()
    Core* p1 = new Core();
    
    std::cerr << " ---------- p2 ---------- " << std::endl;
    // Core::Core()
    // Grad::Grad()
    Core* p2 = new Grad();
    
    std::cerr << " ---------- s1 ---------- " << std::endl;
    // Core::Core()
    Core s1;
    
    std::cerr << " ---------- s2 ---------- " << std::endl;
    // Core::Core()
    // Grad::Grad()
    Grad s2;

    std::cerr << " ---------- p1->grade() ---------- " << std::endl;
    // Core::grade()
    p1->grade();
    
    std::cerr << " ---------- p1->name() ---------- " << std::endl;
    // Core::read()
    p1->name();

    std::cerr << " ---------- p2->grade() ---------- " << std::endl;
    // Grad::grade()
    // Core::grade()
    p2->grade();

    std::cerr << " ---------- p2->name() ---------- " << std::endl;
    // Core::read()
    p2->name();
    
    std::cerr << " ---------- s1.grade() ---------- " << std::endl;
    // Core::grade()
    s1.grade();
    
    std::cerr << " ---------- s1.name() ---------- " << std::endl;
    // Core::name()
    s1.name();

    std::cerr << " ---------- s2.name() ---------- " << std::endl;
    // Core::name()
    s2.name();
    
    std::cerr << " ---------- s2.grade() ---------- " << std::endl;
    // Grad::grade()
    // Core::grade()
    s2.grade();

    return 0;
}
