#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class Deque
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
public:
	void push_front(int value)
	{
		Node* newNode = new Node;
		newNode -> data = value;
		if (size == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else if (size == 1)
		{
			tail = head;
			head = newNode;
			tail->prev = head;
			head->next = tail;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}
	void push_back(int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		if (size == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else if (size == 1)
		{
			head = tail;
			tail = newNode;
			head->next = tail;
			tail->prev = head;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	int pop_front()
	{
		if (size == 0) return -1;
		int value = head->data;
		Node* tempNode = head;
		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else if(size == 2)
		{
			head = tail;
			tail->prev = nullptr;
		}
		else
		{
			head = head->next;
			head->prev = nullptr;
		}
		delete(tempNode);
		size--;
		return value;
	}
	int pop_back()
	{
		if (size == 0) return -1;
		int value = tail->data;
		Node* tempNode = tail;
		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else if (size == 2)
		{
			tail = head;
			head->next = nullptr;
		}
		else
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
		delete(tempNode);
		size--;
		return value;
	}
	int Size()
	{
		return size;
	}
	int empty()
	{
		return (size == 0) ? 1 : 0;
	}
	int front()
	{
		if (size > 0) return head->data;
		else return -1;
	}
	int back()
	{
		if (size > 0) return tail->data;
		else return -1;
	}
};


int main()
{
	Deque deque;
	int cnt, in;
	string input;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		if (input == "push_front")
		{
			cin >> in;
			deque.push_front(in);
		}
		if (input == "push_back")
		{
			cin >> in;
			deque.push_back(in);
		}
		else if (input == "pop_front")
		{
			cout << deque.pop_front() << "\n";
		}
		else if (input == "pop_back")
		{
			cout << deque.pop_back() << "\n";
		}
		else if (input == "size")
		{
			cout << deque.Size() << "\n";
		}
		else if (input == "empty")
		{
			cout << deque.empty() << "\n";
		}
		else if (input == "front")
		{
			cout << deque.front() << "\n";
		}
		else if (input == "back")
		{
			cout << deque.back() << "\n";
		}
	}
	return 0;
}