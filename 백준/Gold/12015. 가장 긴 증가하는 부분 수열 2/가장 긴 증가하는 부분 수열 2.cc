#include <iostream>
using namespace std;

int arr[1000000];
int length;

void BS(int ele, int input)
{
	int start = 0;
	int end = ele - 1;
	int ansidx = ele;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] >= input)
		{
			ansidx = min(ele, mid);
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	arr[ansidx] = input;
}

int main()
{
	cin >> length;

	cin >> arr[0];
	int currElem = 1;

	for (int i = 0; i < length; i++)
	{
		int temp;
		cin >> temp;

		if (arr[currElem - 1] > temp)
		{
			BS(currElem, temp);
		}
		else if (arr[currElem - 1] < temp)
		{
			arr[currElem] = temp;
			currElem++;
		}
	}

	cout << currElem;

	return 0;
}