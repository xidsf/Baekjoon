#include <iostream>
using namespace std;


void Print(int i, int j, int cnt)
{
	if ((i / cnt) % 3 == 1 && (j / cnt) % 3 == 1) cout << ' ';
	else
	{
		if (cnt / 3 == 0) cout << "*";
		else Print(i, j, cnt / 3);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Print(i, j, m);
		}
		cout << '\n';
	}

	return 0;
}