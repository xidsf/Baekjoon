#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> greaterHeap;

	priority_queue<int, vector<int>, less<int>> lessHeap;

	int cnt;
	cin >> cnt;

	int input;

	if (cnt == 1)
	{
		cin >> input;
		cout << input;
		return 0;
	}

	for (int i = 0; i < 2; i++)
	{
		
		cin >> input;

		if (lessHeap.empty())
		{
			lessHeap.push(input);
		}
		else if (lessHeap.top() < input)
		{
			greaterHeap.push(input);
		}
		else
		{
			greaterHeap.push(lessHeap.top());
			lessHeap.pop();
			lessHeap.push(input);
		}
		cout << lessHeap.top() << "\n";
	}

	for (int i = 0; i < cnt - 2; i++)
	{
		cin >> input;

		if (greaterHeap.top() < input)
		{
			greaterHeap.push(input);
		}
		else if(greaterHeap.top() >= input)
		{
			lessHeap.push(input);
		}

		if (greaterHeap.size() > lessHeap.size())
		{
			lessHeap.push(greaterHeap.top());
			greaterHeap.pop();
		}
		else if (lessHeap.size() - greaterHeap.size() == 2)
		{
			greaterHeap.push(lessHeap.top());
			lessHeap.pop();
		}

		cout << lessHeap.top() << "\n";


	}

	return 0;
}