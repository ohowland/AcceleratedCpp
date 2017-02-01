// ask for a person's name, and greet the person.
#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";
    std::string name; 
    std::cin >> name;

    // build the message that we intend to write
    const std::string greeting = "Hello, " + name + "!";

    // build the side * walls
    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";
    
    // build the top and bottom * walls
    const std::string first(second.size(), '*');

    // write all
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;
}
