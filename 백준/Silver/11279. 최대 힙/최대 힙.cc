#include <iostream>
#include <vector>
using namespace std;

class Max_Priority_Queue
{
	
public:
	Max_Priority_Queue()
	{
		heap.push_back(0);
	}

	int Top()
	{
		if (heap.size() >= 2)
		{
			return heap[1];
		}
		else
		{
			return 0;
		}
	}

	void Insert(int data)
	{
		heap.push_back(data);

		int currentindex = heap.size() - 1;

		while (currentindex != 1 && heap[currentindex] >= heap[currentindex / 2])
		{
			ChangeData(currentindex, currentindex / 2);
			currentindex = currentindex / 2;
		}
	}

	void remove()
	{
		if (heap.size() < 2)
		{
			return;
		}

		int ans = heap[1];

		heap[1] = heap.back();
		heap.pop_back();

		ChangeParentWithChild(1);

	}

private:
	vector<int> heap;

	void ChangeParentWithChild(int parnetIndex)
	{
		int rightChildIndex = parnetIndex * 2 + 1;
		int leftChildIndex = parnetIndex * 2;
		int maxIndex = parnetIndex;

		if (leftChildIndex < heap.size())
		{
			if (heap[maxIndex] < heap[leftChildIndex])
				maxIndex = leftChildIndex;
		}
		if (rightChildIndex < heap.size())
		{
			if (heap[maxIndex] < heap[rightChildIndex])
				maxIndex = rightChildIndex;
		}
		
		if (maxIndex != parnetIndex)
		{
			int temp = heap[parnetIndex];
			heap[parnetIndex] = heap[maxIndex];
			heap[maxIndex] = temp;
			ChangeParentWithChild(maxIndex);
		}
	}

	void ChangeData(int idx1, int idx2)
	{
		int temp = heap[idx1];
		heap[idx1] = heap[idx2];
		heap[idx2] = temp;
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Max_Priority_Queue mQ;

	int cnt;
	cin >> cnt;
	int input;
	for (int i = 0; i < cnt; i++)
	{
		cin >> input;
		if (input == 0)
		{
			cout << mQ.Top() << "\n";
			mQ.remove();
		}
		else
		{
			mQ.Insert(input);
		}
	}

	return 0;
}