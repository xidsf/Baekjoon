#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool graph[101][101];
bool visited[101];
stack<int> s;
int cnt;

void dfs(int start)
{
    s.push(start);
    int current;
    bool isChanged = false;
    while (!s.empty())
    {
        isChanged = false;
        current = s.top();
        for (int i = 0; i < cnt; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                isChanged = true;
                s.push(i);
                visited[i] = true;
                break;
            }
        }
        if (!isChanged) s.pop();
    }

}

int main() {
    

    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        memset(visited, 0, 101 * sizeof(bool));

        for (int j = 0; j < cnt; j++)
        {
            if (graph[i][j] && !visited[j])
            {
                dfs(i);
            }
        }
        
        for (int i = 0; i < cnt; i++)
        {
            if (visited[i]) cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }

    return 0;
}
