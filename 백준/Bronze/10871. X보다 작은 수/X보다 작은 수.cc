#include <iostream>
using namespace std;

int main()
{
	int *n;
	int cnt;
	int num;
	cin >> cnt;
	cin >> num;
	n = new int[cnt];
	for (int i = 0; i < cnt; i++) cin >> n[i];
	
	for (int i = 0; i < cnt; i++)
	{
		if (n[i] < num) cout << n[i] << " ";
	}
	return 0;
}