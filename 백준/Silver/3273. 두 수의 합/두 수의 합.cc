#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cnt;
	cin >> cnt;
	int* arr = new int[cnt];
	for (int  i = 0; i < cnt; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + cnt);

	int start = 0 , end = cnt - 1, temp;

	int target, result = 0;
	cin >> target;

	while (start != end)
	{
		if (start == end) temp = 0;
		else temp = arr[start] + arr[end];

		if (temp == target) result++;

		if (temp >= target) end--;
		else start++;
	}
	cout << result;
    return 0;
}