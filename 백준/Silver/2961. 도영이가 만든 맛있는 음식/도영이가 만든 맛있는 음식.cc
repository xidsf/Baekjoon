#include <iostream>
#include <vector>
using namespace std;

vector<int> lemon;
vector<int> coffee;
int minVal = INT32_MAX;

void Func(int start, int leftSelect, pair<int, int> currentState)
{
	if (leftSelect > 0)
	{
		for (int i = start + 1; i < lemon.size() - leftSelect + 1; i++)
		{
			pair<int, int> tempState = currentState;

			tempState.first *= lemon[start];
			tempState.second += coffee[start];

			Func(i, leftSelect - 1, tempState);
		}
	}
	else
	{
		currentState.first *= lemon[start];
		currentState.second += coffee[start];

		minVal = min(minVal, abs(currentState.first - currentState.second));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int length;
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;

		lemon.push_back(temp1);
		coffee.push_back(temp2);
	}

	int ans = INT32_MAX;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i; j++)
		{
			Func(j, i, { 1, 0 });
		}
	}

	cout << minVal;

	return 0;
}