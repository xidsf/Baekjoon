#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int length;
vector<int> arr;
vector<int> targets;

int BS(int target)
{
	int start = 0;
	int end = length - 1;
	int minIdx = INT32_MAX;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] >= target)
		{
			if (arr[mid] == target) minIdx = min(minIdx, mid);
			end = mid - 1;
		}
		else if (arr[mid] < target)
		{
			start = mid + 1;
		}
	}
	
	if (minIdx == INT32_MAX || arr[minIdx] != target) return 0;

	start = minIdx;
	end = length - 1;
	int maxIdx = length;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] > target)
		{
			maxIdx = min(maxIdx, mid);
			end = mid - 1;
		}
		else if (arr[mid] <= target)
		{
			start = mid + 1;
		}
	}

	return maxIdx - minIdx;
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
		cout << BS(targets[i]) << "\n";
	}

	return 0;
}