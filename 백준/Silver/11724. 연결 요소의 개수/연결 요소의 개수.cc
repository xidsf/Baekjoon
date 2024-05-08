#include <iostream>
#include <stack>
using namespace std;

int arr[1001][1001] = { 0, };
int visited[1001] = { 0, };
const int MAX_SIZE = 1001;
stack<int> s;

void dfs()
{
    int current, temp;
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        visited[current] = 1;

        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (arr[current][i] == 1)
            {
                arr[current][i] = 0;
                arr[i][current] = 0;
                s.push(i);
            }
        }
    }
}

int main() {
    
    int size, line;
    int temp1, temp2, cnt = 0, ans = 0;
    cin >> size >> line;

    for (int i = 0; i < line; i++)
    {
        cin >> temp1 >> temp2;
        arr[temp1 - 1][temp2 - 1] = 1;
        arr[temp2 - 1][temp1 - 1] = 1;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1)
            {
                ans++;
                s.push(i);
                dfs();
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 0) ans++;
    }

    cout << ans;
}
