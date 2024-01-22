#include <iostream>
using namespace std;

int main()
{
	int total, cnt, price, number;
	int sum = 0;
	cin >> total;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> price >> number;
		sum += price * number;
	}
	if (sum == total) cout << "Yes";
	else cout << "No";

	
	return 0;
}