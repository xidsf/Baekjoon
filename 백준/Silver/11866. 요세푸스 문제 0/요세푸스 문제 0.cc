#include <iostream>
#include <deque>
using namespace std;


int main()
{
	int num, gap;
	cin >> num >> gap;

	deque<int> d;
	int arr[1000];
	for (int i = 1; i <= num; i++)
	{
		d.push_back(i);
	}

	int cnt = 0;
	while (!d.empty())
	{
		for (int i = 0; i < gap - 1; i++)
		{
			int temp = d.front();
			d.pop_front();
			d.push_back(temp);
		}

		arr[cnt] = d.front();
		d.pop_front();
		cnt++;
	}

	cout << "<";
	for (int i = 0; i < num - 1; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << arr[num - 1] << ">";
	return 0;
}