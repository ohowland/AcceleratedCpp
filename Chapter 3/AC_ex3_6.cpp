// Ex 3.6 dealing with division by zero.

#include <iostream>

int main()
{	
	int input = 0;
	int count = 0;
	int sum = 0;

	std::cout << "input: ";
	while (std::cin >> input) {
		++count;
		sum += input;
	}

	double average = 0;
	if (count != 0)
		average = sum/count;

	std::cout << average << std::endl;
	
	return 0;
}
