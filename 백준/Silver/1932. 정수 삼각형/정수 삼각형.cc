#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> input;

	int currentIndex = 1;
	for (int height = 1; height <= input; height++)
	{
		int temp;
		if (height == 1)
		{
			cin >> temp;
			v.push_back(temp);
			continue;
		}

		int leftIndex = currentIndex - (height - 1);
		int rightIndex = currentIndex - 1;

		for (int j = 0; j < height; j++)
		{
			cin >> temp;
			
			if (j == 0)
			{
				temp = temp + v[leftIndex];
			}
			else if (j == height - 1)
			{
				temp = temp + v[rightIndex];
			}
			else
			{
				temp = temp + max(v[leftIndex + j - 1], v[leftIndex + j]);
			}
			v.push_back(temp);

			currentIndex++;
		}
	}

	int maxSize = 0;

	for (int i = currentIndex - 1; i >= currentIndex - input ; i--)
	{
		maxSize = max(maxSize, v[i]);
	}

	cout << maxSize;

	return 0;
}