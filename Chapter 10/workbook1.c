int main()
{
	int x = 5;

	//p points to x
	int* p = &x;
	cout << "x = " << x << endl;

	*p = 6;
	cout << "x = " << x << endl;

	return 0;
}
