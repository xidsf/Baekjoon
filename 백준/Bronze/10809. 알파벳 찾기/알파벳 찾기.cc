#include <iostream>
#include <cstring>
using namespace std;
const int MAX_LENGTH = 101;


int main()
{
	char* ch;
	ch = new char[MAX_LENGTH];
	cin >> ch;
	int length = strlen(ch);
	bool isMinus = true;
	for (int i = 97; i <= 122; i++)
	{
		isMinus = true;
		for (int j = 0; j < length; j++)
		{
			if (ch[j] == char(i))
			{
				cout << j << " ";
				isMinus = false;
				break;
			}
		}
		if (isMinus) cout << -1 << " ";
	}

	delete[]ch;
	return 0;
}