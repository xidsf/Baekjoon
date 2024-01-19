#include <iostream>
using namespace std;

int main()
{
	cout << fixed;
	cout.precision(9);
	double a, b;
	cin >> a >> b;
	double c = a / b;
	cout << c;
	return 0;
}