#include <iostream>
#include <string>
#include "Vec.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	string s;
	Vec<string> v;

	while(cin >> s)
		v.push_back(s);

    cout << "size before erase() member function: " << v.size() << endl;

    v.erase(v.begin()+1);

    cout << "size after erase() member function: " << v.size() << endl;
	
	for(Vec<string>::iterator iter = v.begin(); 
		iter != v.end(); iter++)
	    cout << *iter << endl; 
    
    v.clear();

    cout << "size after clear() member function: " << v.size() << endl;

    return 0;
}
