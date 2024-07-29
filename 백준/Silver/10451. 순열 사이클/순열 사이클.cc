#include <iostream>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	

	for (int i = 0; i < testCase; i++)
	{
		int cnt;
		cin >> cnt;
		int arr[1000];

		for (int j = 0; j < cnt; j++)
		{
			int input;
			cin >> input;
			
			arr[j] = input - 1;
		}

		int ans = 0;

		for (int j = 0; j < cnt; j++)
		{
			if (arr[j] != -1)
			{
				ans++;
				int visited = arr[j];
				while (arr[visited] != -1)
				{
					int temp = arr[visited];
					arr[visited] = -1;
					visited = temp;
				}

			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}