#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int graph1[50000];
int graph2[50000];
bool visited[20000];
int distances[20000] = { 0, };


queue<int> q;
int nodeCount, inputCount;

int bfs()
{
    int qSize, distance = -1, current;
    visited[0] = true;
    q.push(0);
    while (!q.empty())
    {
        qSize = q.size();
        distance++;
        for (int j = 0; j < qSize; j++)
        {
            current = q.front();
            distances[current] = distance;
            for (int i = 0; i < inputCount; i++)
            {
                if (graph1[i] == current && !visited[graph2[i]])
                {
                    visited[graph2[i]] = true;
                    q.push(graph2[i]);
                }
                if (graph2[i] == current && !visited[graph1[i]])
                {
                    visited[graph1[i]] = true;
                    q.push(graph1[i]);
                }
            }
            q.pop();
        }
    }
    return distance;
}


int main() {
    int max = 0;

    cin >> nodeCount >> inputCount;

    int temp1, temp2;
    
    for (int i = 0; i < inputCount; i++)
    {
        cin >> temp1 >> temp2;
        graph1[i] = temp1 - 1;
        graph2[i] = temp2 - 1;
        
    }
    max = bfs();

    int maxCount = 0;
    bool isShownMinNum = false;

    for (int i = 0; i < nodeCount; i++)
    {
        if (distances[i] == max)
        {
            maxCount++;
            if (!isShownMinNum)
            {
                cout << i + 1 << " ";
                isShownMinNum = true;
            }
        }   
    }
    cout << max << " " << maxCount << "\n";
    return 0;
}
