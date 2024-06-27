#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> arr;
	int cnt, num;
	int temp;
	cin >> cnt >> num;
	for (int i = 0; i < cnt; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	int ans = 0;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (num - arr[j] == arr[i]) ans++;
		}
	}

	cout << ans;

	return 0;
}