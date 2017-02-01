/*  This program helps a student compute their final grade.
	40% comes from final exam, 20% from midterm, and 40%
	from homework. */

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;			using std::setprecision;
using std::cout;		using std::string;
using std::endl;		using std::streamsize;

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
	
	int count = 0;	// the number of grades read so far.
	double sum = 0; // the sum of grades read so far.

	double x;		// a variable into which to read.

	/*  invariant:
		we have read count grades so far, and sum is the sum
		of the first count grades. */
	while (cin >> x) {
		++count;
		sum += x;
	}

	// write the result
	streamsize prec = cout.precision();
	cout << "Final grade: " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
		 << setprecision(prec) << endl;

	return 0;
}
