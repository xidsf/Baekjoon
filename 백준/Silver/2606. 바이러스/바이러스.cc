#//바이러스
#include <iostream>
#include <stack>
using namespace std;

#define MAX 101
int n, m;
int cnt = 0;
int arr[MAX][MAX];
int visited[MAX] = { 0 };
stack<int> s;

void bfs(int v) {

    s.push(1);
    int current;
    visited[1] = -1;
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        for (int i = 0; i < MAX; i++)
        {
            if (arr[current][i] == 1 && visited[i] != -1) 
            {
                s.push(i);
                visited[i] = -1;
                cnt++;
            }
        }
    }
}



int main() {
    cin >> n >> m;
    for (auto i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    bfs(1);
    cout << cnt;

}