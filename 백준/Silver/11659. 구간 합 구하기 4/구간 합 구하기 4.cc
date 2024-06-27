#include <iostream>
#include <vector>
using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int numCount, calcCount;;
	cin >> numCount >> calcCount;
	
	vector<int> arr;
	int temp;
	for (int i = 0; i < numCount; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	vector<int> prefixSum;
	prefixSum.push_back(0);
	int tempSum = 0;
	prefixSum.push_back(arr[0]);
	for (int i = 1; i < numCount; i++)
	{
		prefixSum.push_back(prefixSum[i] + arr[i]);
	}

	int i, j, sum = 0;
	for (int k = 0; k < calcCount; k++)
	{
		cin >> i >> j;
		i--;
		if (i != j)
		{
			cout << prefixSum[j] - prefixSum[i] << "\n";
		}
		else
		{
			cout << prefixSum[i] << "\n";
		}
	}


	return 0;
}