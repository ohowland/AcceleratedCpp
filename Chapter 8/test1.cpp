#include <iterator>
#include <iostream>
		
template <class Out>
void func(Out os)
{
	std::cout << "numero: " << os;
}

template void func<int>(int);
