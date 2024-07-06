#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numCard;

bool FindCard(int target)
{
	int start = 0;
	int end = numCard.size() - 1;
	int mid;
	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (target < numCard[mid])
		{
			end = mid - 1;
		}
		else if(target > numCard[mid])
		{
			start = mid + 1;
		}
		else
		{
			return true;
		}

		if (start == end)
		{
			if (target == numCard[start])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;

	int input;
	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		numCard.push_back(input);
	}

	int testCnt;
	cin >> testCnt;

	vector<int> testCard;

	for (int i = 0; i < testCnt; i++)
	{
		cin >> input;
		testCard.push_back(input);
	}

	sort(numCard.begin(), numCard.end());

	for (int i = 0; i < testCard.size(); i++)
	{
		if (FindCard(testCard[i]))
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		cout << " ";
	}

	return 0;
}