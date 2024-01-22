#include <iostream>
using namespace std;

int main()
{
	int *n;
	int cnt;
	cin >> cnt;
	n = new int[cnt];
	for (int i = 0; i < cnt; i++) cin >> n[i];
	int num, ncnt;
	ncnt = 0;
	cin >> num;
	for (int i = 0; i < cnt; i++)
	{
		if (n[i] == num) ncnt++;
	}
	cout << ncnt;
	return 0;
}