#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool graph[101][101];
bool visited[101];
int scores[101] = { 0, };
queue<int> q;
int cnt;

int bfs(int c)
{
    int qSize, score = -1, current;
    q.push(c);
    visited[c] = true;
    while (!q.empty())
    {
        qSize = q.size();
        score++;
        for (int j = 0; j < qSize; j++)
        {
            current = q.front();
            for (int i = 0; i < cnt; i++)
            {
                if (graph[current][i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
            q.pop();
        }
    }
    return score;
}


int main() {
    int min = INT32_MAX;
    cin >> cnt;
    int temp1, temp2;
    cin >> temp1 >> temp2;
    while (temp1 != -1 && temp2 != -1)
    {
        graph[temp1 - 1][temp2 - 1] = true;
        graph[temp2 - 1][temp1 - 1] = true;
        cin >> temp1 >> temp2;
    }

    for (int i = 0; i < cnt; i++)
    {
        memset(visited, 0, 101 * sizeof(bool));
        scores[i] = bfs(i);
        if (min > scores[i]) min = scores[i];
    } 

    int minCount = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (scores[i] == min) minCount++;
    }

    cout << min << " " << minCount << "\n";
    for (int i = 0; i < cnt; i++)
    {
        if (scores[i] == min) cout << i + 1 << " ";
    }

    return 0;
}
