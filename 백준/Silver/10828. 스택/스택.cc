#include <iostream>
using namespace std;

class Stack
{
private:
	int arr[10000];
	int arrCount = 0;
public:
	void push(int value)
	{
		arr[arrCount] = value;
		arrCount++;
	}
	int pop()
	{
		if (arrCount == 0) return -1;
		else
		{
			arrCount--;
			return arr[arrCount];
		}
	}
	int size()
	{
		return arrCount;
	}
	int empty()
	{
		if (arrCount == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int top()
	{
		if (arrCount == 0) return -1;
		else
		{
			return arr[arrCount - 1];
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Stack stack;
	int cnt;
	string input;
	int num;

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> num;
			stack.push(num);
		}
		else if (input == "pop")
		{
			cout << stack.pop() << "\n";
		}
		else if (input == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (input == "empty")
		{
			cout << stack.empty() << "\n";
		}
		else if (input == "top")
		{
			cout << stack.top() << "\n";
		}
	}


	return 0;
}