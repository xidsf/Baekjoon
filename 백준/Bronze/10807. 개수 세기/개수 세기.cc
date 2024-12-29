#include <iostream>

int arr[201] = {0, };

int main()
{
	int input;
	std::cin >> input;

	for (int i = 0; i < input; i++)
	{
		int num;
		std::cin >> num;
		arr[num + 100]++;
	}

	std::cin >> input;
	std::cout << arr[input + 100];

	return 0;
}