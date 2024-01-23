#include <iostream>
using namespace std;

int main()
{
	int *n;
	int cnt;
	cin >> cnt;
	n = new int[cnt];
	for (int i = 0; i < cnt; i++) cin >> n[i];
	
	int min = 1000000;
	int max = -1000000;
	for (int i = 0; i < cnt; i++)
	{
		if (max < n[i]) max = n[i];
		if (min > n[i]) min = n[i];
	}
	cout << min << " " << max;
	return 0;
}