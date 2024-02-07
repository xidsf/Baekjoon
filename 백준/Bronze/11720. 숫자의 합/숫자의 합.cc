#include <iostream>
using namespace std;
const int MAX_LENGTH = 101;

int main()
{
	char* ch;
	ch = new char[MAX_LENGTH];
	int cnt;
	cin >> cnt >> ch;
	int sum = 0;
	for (int c = 0; ch[c] != '\0'; c++)
	{
		sum += int(ch[c]) - 48;
	}
	cout << sum;
	delete[]ch;
	return 0;
}