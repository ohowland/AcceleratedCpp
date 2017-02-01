#include <iostream>
#include <vector>
#include "readin.h"

using std::cin;		using std::vector;
using std::cout;	using std::string;
using std::endl;

int main()
{
	vector<double> avg_v;	
	readin(cin, avg_v);

	double sum = 0;
	double cnt = 0;
	for (vector<double>::iterator it = avg_v.begin(); it != avg_v.end(); ++it, ++cnt)
		sum += avg_v[cnt];
	
	double avg = sum / cnt;

	cout << endl << avg << endl;
	return 0;
}

