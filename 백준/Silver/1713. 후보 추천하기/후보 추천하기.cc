#include <iostream>
using namespace std;

struct Student
{
	int recommend = 0;
	int sequence = 0;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size, cnt;
	cin >> size >> cnt;

	Student arr[100];
	int currentSize = 0;

	for (int i = 0; i < cnt; i++)
	{
		int input;
		
		cin >> input;
		input--;

		if (arr[input].recommend > 0)
		{
			arr[input].recommend++;
			continue;
		}

		if (currentSize == size)
		{
			Student* dangerStudent = nullptr;

			for (int j = 0; j < 100; j++)
			{
				if (arr[j].recommend > 0)
				{
					if (dangerStudent == nullptr)
					{
						dangerStudent = &arr[j];
					}
					else if (dangerStudent->recommend > arr[j].recommend || (dangerStudent->recommend == arr[j].recommend && dangerStudent->sequence > arr[j].sequence))
					{
						dangerStudent = &arr[j];
					}
				}
			}

			dangerStudent->recommend = 0;
			dangerStudent->sequence = 0;

			arr[input].recommend = 1;
			arr[input].sequence = i;
		}
		else
		{
			arr[input].recommend++;
			arr[input].sequence = i;
			currentSize++;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (arr[i].recommend > 0)
		{
			cout << i + 1 << " ";
		}
	}

	return 0;
}