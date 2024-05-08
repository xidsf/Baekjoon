#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;


bool arr[1001][1001] = { 0, };
bool isVisited[1001] = { 0, };
const int MAX_SIZE = 1001;
stack<int> s;
queue<int> q;


void dfs()
{
    int current, min;
    while (!s.empty())
    {
        min = INT32_MAX;
        current = s.top();
        
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (arr[current][i] && !isVisited[i])
            {
                if (min > i) min = i;
            }
        }
        if (min != INT32_MAX)
        {
            s.push(min);
            isVisited[min] = true;
            cout << min + 1 << " ";
        }
        else
        {
            s.pop();
        }
    }
}

void bfs()
{
    int current;
    while (!q.empty())
    {
        current = q.front();
        q.pop();
        cout << current + 1 << " ";
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (arr[current][i] && !isVisited[i])
            {
                isVisited[i] = true;
                q.push(i);
            }
        }
        
    }
}


int main() {
    
    int cnt, line;
    int temp1, temp2, start;
    cin >> cnt >> line >> start;

    for (int i = 0; i < line; i++)
    {
        cin >> temp1 >> temp2;
        arr[temp1 - 1][temp2 - 1] = true;
        arr[temp2 - 1][temp1 - 1] = true;
    }
    cout << start << " "; 
    isVisited[start - 1] = true;
    s.push(start - 1);
    dfs();
    
    memset(isVisited, 0, sizeof(bool) * 1001);

    cout << "\n";
    isVisited[start - 1] = true;
    q.push(start - 1);
    bfs();

    return 0;
}
