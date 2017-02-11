#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Student_info.h"

using namespace std;


int main()
{
    Student_info s1;
    Student_info s2;

    // assign s1 values. assign them to s2.
    // does s2 recieve copies, or does it point to the same object?
    s1.read(cin);
    s2 = s1; 
    cout << "FIRST ASSIGNMENTS: s1: " << s1.grade() << ", s2: " << s2.grade() << endl;

    // assign new values to s1 but not s2
    s1.read(cin);
    cout << "SECOND ASSIGNEMNTS: s1: " << s1.grade() << ", s2: " << s2.grade() << endl;

    s1.~Student_info();

    cout << "s1 destroyed, the value of s2 is: " << s2.grade() << endl;

    return 0;
}
