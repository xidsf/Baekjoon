#include <iostream>
#include <queue>
using namespace std;


bool arr[501][501] = { 0, };
bool isVisited[501] = { 0, };
const int MAX_SIZE = 501;
queue<int> q;
int ans = -1;

void bfs()
{
    int current, qSize, depth = 0;
    while (!q.empty())
    {
        depth++;
        if (depth >= 3)
        {
            q.pop();
            ans++;
            continue;
        }
        qSize = q.size();
        for (int j = 0; j < qSize; j++)
        {
            current = q.front();
            ans++;
            q.pop();
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
}


int main() {
    
    int cnt, line;
    int temp1, temp2;
    cin >> cnt >> line;

    for (int i = 0; i < line; i++)
    {
        cin >> temp1 >> temp2;
        arr[temp1 - 1][temp2 - 1] = true;
        arr[temp2 - 1][temp1 - 1] = true;
    }

    isVisited[0] = true;
    q.push(0);
    bfs();

    cout << ans;

    return 0;
}
