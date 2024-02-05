#include <iostream>
using namespace std;

int main()
{
	int cnt = 0;
	int temp;
	int input;
	int arrdiv[10];
	bool isequal = false;
	for (int i = 0; i < 10; i++)
	{
		arrdiv[i] = -1;
	}

	for(int i = 0; i < 10; i++)
	{
		cin >> input;
		temp = input % 42;
		for (int j = 0; j < cnt; j++)
		{
			if (arrdiv[j] == temp) isequal = true;
		}
		if (isequal)
		{
			isequal = false;
			continue;
		}
		arrdiv[cnt] = temp;
		cnt++;
	}
	cout << cnt;

	return 0;
}