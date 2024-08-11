#include <iostream>
#include <queue>
#include <deque>
using namespace std;

typedef struct node
{
	int num;
	bool target;
} Node;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int documCnt, cnt;

		cin >> documCnt >> cnt;

		deque<Node> arr;
		priority_queue<int, vector<int>, less<int>> pq;

		for (int i = 0; i < documCnt; i++)
		{
			int temp;
			cin >> temp;
			pq.push(temp);
			Node node;
			node.num = temp;
			
			if (i == cnt) node.target = true;
			else node.target = false;

			arr.push_back(node);
		}

		int ans = 1;

		while (!arr.empty())
		{
			int current_priority = pq.top();

			Node node = arr.front();

			while (node.num != current_priority)
			{
				arr.pop_front();
				arr.push_back(node);
				node = arr.front();
			}

			if (node.target == true)
			{
				cout << ans << "\n";
				break;
			}
			else
			{
				arr.pop_front();
				ans++;
				pq.pop();
			}
		}
	}

	return 0;
}