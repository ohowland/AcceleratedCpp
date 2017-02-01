/*  This program helps a student compute their final grade.
	40% comes from final exam, 20% from midterm, and 40%
	from homework. */

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;			using std::setprecision;
using std::cout;		using std::string;
using std::endl;		using std::streamsize;
using std::sort;		using std::vector;


int main()
{
	// ask for an read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for an read the midterm and final grades
	cout << "Please enter your midterm and final exam grades :";
	double midterm, final;
	cin >> midterm >> final;

	// ask for homework grades.
	cout << "Enter all your homework grades, "
			"followed by end-of-file: ";
	
	double x;		// a variable into which to read.
	vector<double> homework; // a vector to hold read values

	// homework contains all homework grades.	
	while (cin >> x)
		homework.push_back(x);

	// check that the student entered some homework grades.
	typedef vector<double>::size_type vec_sz; // define typedef.
	vec_sz size = homework.size(); // store typedef in 'size'.
	if (size == 0) {
		cout << endl << "you must enter your grades. "
						"Please try again." << endl;
		return 1;
	}
	
	sort(homework.begin(), homework.end()); // sort if defined in <algorithm>.

	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
						   : homework[mid];
	// write the result
	streamsize prec = cout.precision();
	cout << "Final grade: " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median 
		 << setprecision(prec) << endl;
	return 0;
}
