#include "Str.h"

using std::endl;
using std::cout;
using std::cin; 

int main()
{

    Str name;
    cin >> name; 
    cout << "hi " << name << endl;
    
    Str prepend_exp("explicit) hey mang");
    Str prepend_imp = "(implicit) hey mang";

    cout << prepend_exp + name << endl;
    cout << prepend_imp + name << endl;

    return 0;
}
