#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int length;
vector<int> arr;
vector<int> targets;

bool BS(int target)
{
	int start = 0;
	int end = length - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == target)
		{
			return true;
		}
		else
		{
			if (arr[mid] > target)
			{
				end = mid - 1;
			}
			else if (arr[mid] < target)
			{
				start = mid + 1;
			}
		}
	}
	return false;
}

int main()
{
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		int temp;
		cin >> temp;
		targets.push_back(temp);
	}

	for (int i = 0; i < targets.size(); i++)
	{
		if (BS(targets[i]))
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}

	return 0;
}