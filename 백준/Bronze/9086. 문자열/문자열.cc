#include <iostream>
using namespace std;
const int MAX_LENGTH = 1001;

int main()
{
	char* arr;
	int cnt;
	arr = new char[MAX_LENGTH];
	cin >> cnt;
	for (int j = 0; j < cnt; j++)
	{
		cin >> arr;
		cout << arr[0];
		for (int i = 0; i < MAX_LENGTH; i++)
		{
			if (arr[i] == '\0')
			{
				cout << arr[i - 1] << endl;
				break;
			}
		}
	}
	
	delete[]arr;
	return 0;
}