#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt = n / 4;
	if (n % 4 != 0) cnt++;
	for (int i = 0; i < cnt; i++)
	{
		cout << "long ";
	}
	cout << "int";
	return 0;
}