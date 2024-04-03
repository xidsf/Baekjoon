#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
	vector<int> queue;
	int begin = 0;
	int end = 0;
public:
	void push(int value)
	{
		queue.push_back(value);
		end++;
	}
	int pop()
	{
		if (begin == end) return -1;
		int temp = queue.at(begin);
		begin++;
		return temp;
	}
	int size()
	{
		return end - begin;
	}
	int empty()
	{
		return (begin == end) ? 1 : 0;
	}
	int front()
	{
		if (begin == end) return -1;
		else return queue.at(begin);
	}
	int back()
	{
		if (begin == end) return -1;
		else return queue.at(end - 1);
	}


};


int main()
{
	Queue queue;
	int cnt, in;
	string input;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		if (input == "push")
		{
			cin >> in;
			queue.push(in);
		}
		else if (input == "pop")
		{
			cout << queue.pop() << "\n";
		}
		else if (input == "size")
		{
			cout << queue.size() << "\n";
		}
		else if (input == "empty")
		{
			cout << queue.empty() << "\n";
		}
		else if (input == "front")
		{
			cout << queue.front() << "\n";
		}
		else if (input == "back")
		{
			cout << queue.back() << "\n";
		}
	}

	return 0;
}
