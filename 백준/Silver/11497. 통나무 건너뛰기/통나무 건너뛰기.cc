#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10000];

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int cnt;
		cin >> cnt;

		vector<int> v;
		for (int j = 0; j < cnt; j++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		arr[0] = v[0];
		arr[cnt - 1] = v[1];

		int currentMaxDiff = v[1] - v[0];
		int currentIdx = 2;
		int start = 1;
		int end = cnt - 2;

		while (start <= end)
		{
			int firstLeft = max(v[currentIdx] - arr[start - 1], v[min(currentIdx + 1, cnt - 1)] - arr[end + 1]);
			int firstRight = max(v[min(currentIdx + 1, cnt - 1)] - arr[start - 1], v[currentIdx] - arr[end + 1]);

			if (firstLeft <= firstRight)
			{
				arr[start] = v[currentIdx];
				arr[end] = v[min(currentIdx + 1, cnt - 1)];
				currentMaxDiff = max(currentMaxDiff, firstLeft);
			}
			else
			{
				arr[start] = v[min(currentIdx + 1, cnt - 1)];
				arr[end] = v[currentIdx];
				currentMaxDiff = max(currentMaxDiff, firstRight);
			}
			currentIdx += 2;
			start++;
			end--;
		}

		cout << currentMaxDiff << "\n";

	}

	return 0;
}