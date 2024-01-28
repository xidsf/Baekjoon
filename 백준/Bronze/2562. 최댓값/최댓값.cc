#include <iostream>
using namespace std;

int main()
{
	int *n;
	int cnt = 9;
	n = new int[cnt];
	for (int i = 0; i < cnt; i++) cin >> n[i];
	
	int max = 0;
	int index = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (max < n[i])
		{
			max = n[i];
			index = i;
		}
	}
	cout << max << endl << index+1;
	delete[]n;
	return 0;
}