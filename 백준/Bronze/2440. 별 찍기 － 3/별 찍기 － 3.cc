#include <iostream>
using namespace std;

int main()
{
    int cnt;
	cin >> cnt;
	for (int i = cnt; i > 0 ; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << '*';
		}
		cout << "\n";
	}

    return 0;
}