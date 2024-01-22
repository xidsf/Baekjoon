#include <iostream>
using namespace std;

int main()
{
	int n;
	int num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		num += i;
	}
	cout << num;
	return 0;
}