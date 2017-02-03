#include <list>
#include <string>

class lists {
public:
	std::list<std::string> strpt() { return _strpt; }
	void add_str(const std::string);
	
private:
	std::list<std::string> _strpt;
};


