#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> arr;

int main()
{
	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		long long temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int start = 0;
	int end = arr.size() - 1;
	long long minAbs = 2000000000;
	long long currentMin[2] = {0, 0};

	
	while (start < end)
	{
		int sum = arr[start] + arr[end];

		if (minAbs > abs(sum))
		{
			minAbs = abs(sum);
			currentMin[0] = arr[start];
			currentMin[1] = arr[end];
			if (minAbs == 0) break;
		}

		if (sum < 0)
		{
			start++;
		}
		else if (sum > 0)
		{
			end--;
		}
	}

	cout << currentMin[0] << " " << currentMin[1];

	return 0;
}