#include <iostream>
using namespace std;




void Cut(int x, int y, int len, int currweight)
{
	int tempWeight;
	if (len == 1)
	{
		cout << currweight;
	}
	else
	{
		tempWeight = (len / 2) * (len / 2);
		if (x < len / 2 && y < len / 2)
		{
			Cut(x, y, len / 2, currweight);
		}
		else if (x >= len / 2 && y < len / 2)
		{
			Cut(x - (len / 2), y , len / 2, currweight + tempWeight * 1);
		}
		else if (x < len / 2 && y >= len / 2)
		{
			Cut(x, y - (len / 2), len / 2, currweight + tempWeight * 2);
		}
		else if (x >= len / 2 && y >= len / 2)
		{
			Cut(x - (len / 2), y - (len / 2), len / 2, currweight + tempWeight * 3);
		}
		
		
		
	}
}

int main()
{
	int N, maxlen = 1;
	int ansX, ansY;
	cin >> N >> ansY >> ansX;


	for (int i = 0; i < N; i++)
	{
		maxlen *= 2;
	}


	Cut(ansX, ansY, maxlen, 0);


	return 0;
}