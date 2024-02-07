#include <iostream>
using namespace std;
const int MAX_LENGTH = 1001;

int main()
{
	char* arr;
	int cnt;
	arr = new char[MAX_LENGTH];
	cin >> arr;
	cin >> cnt;
	cout << arr[cnt - 1];
	delete[]arr;
	return 0;
}