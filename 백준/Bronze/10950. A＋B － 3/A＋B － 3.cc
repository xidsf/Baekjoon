#include <iostream>
using namespace std;

int main()
{
	int cnt;
	int* a, *b;
	cin >> cnt;
	a = new int[cnt];
	b = new int[cnt];
	for (int i = 0; i < cnt; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < cnt; i++)
	{
		cout << a[i] + b[i] << endl;
	}
	return 0;
}