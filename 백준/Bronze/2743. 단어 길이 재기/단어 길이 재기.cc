#include <iostream>
using namespace std;
const int MAX_LENGTH = 101;

int main()
{
	char* arr;
	int cnt;
	arr = new char[MAX_LENGTH];
	cin >> arr;

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (arr[i] == '\0')
		{
			cout << i;
			break;
		}
	}

	delete[]arr;
	return 0;
}