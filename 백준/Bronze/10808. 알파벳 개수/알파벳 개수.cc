#include <iostream>
#include <string>
using namespace std;


int main()
{
	int alphaCount = (int)('z' - 'a' + 1);
	int* arr = new int[alphaCount];
	for (int i = 0; i < alphaCount; i++)
	{
		arr[i] = 0;
	}
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		arr[(int)input[i] - 'a']++;
	}

	for (int i = 0; i < alphaCount; i++)
	{
		cout << arr[i] << " ";
	}
	
	return 0;
}
