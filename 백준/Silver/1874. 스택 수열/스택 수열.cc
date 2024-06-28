#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;

	int currentInputNum = 1;
	int currentIndex = 0;
	int maxNum;
	cin >> maxNum;
	vector<int> arr;
	vector<char> output;
	int input;
	
	for (int i = 0; i < maxNum; i++)
	{
		cin >> input;
		arr.push_back(input);
	}

	while (currentIndex < arr.size())
	{
		if (s.empty() || arr[currentIndex] > s.top())
		{
			s.push(currentInputNum);
			output.push_back('+');
			currentInputNum++;
		}
		else if(arr[currentIndex] == s.top())
		{
			s.pop();
			output.push_back('-');
			currentIndex++;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	} 

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "\n";
	}

	return 0;
}