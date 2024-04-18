#include <iostream>

#include <string.h>

#include <queue>

using namespace std;

int n, m;

int map[300][300];

int cmap[300][300];

int visited[300][300];

int dx[] = { 0, 0, 1, -1 };

int dy[] = { 1, -1, 0, 0 };

pair<int, int> dir[] = { make_pair(0, 1), make_pair(1, 0), make_pair(-1, 0), make_pair(0, -1) };

void bfs(int a, int b) {

    queue<pair<int, int>> q;

    q.push({ a, b });

    visited[a][b] = 1;
    pair<int, int> currentPos;
    pair<int, int> tempPos;

    while (!q.empty()) {
        currentPos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            tempPos.first = currentPos.first + dir[i].first;
            tempPos.second = currentPos.second + dir[i].second;
            if (tempPos.first >= 0 && tempPos.first < n && tempPos.second >= 0 && tempPos.second < m)
            {
                if (map[tempPos.first][tempPos.second] > 0 && visited[tempPos.first][tempPos.second] != 1)
                {
                    visited[tempPos.first][tempPos.second] = 1;
                    q.push(tempPos);
                }
            }
        }

    }

}

int melt(int x, int y) { // 4방향 물인 것들 세기

    int cnt = 0;

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];

        int ny = y + dy[i];

        if (map[nx][ny] == 0) cnt += 1;

    }

    return cnt;

}

int main() {

    cin >> n >> m;



    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> map[i][j];

        }

    }

    int year = 0;

    while (1) {

        int cnt = 0;

        memset(visited, 0, sizeof(visited));

        memset(cmap, 0, sizeof(cmap));

        for (int i = 0; i < n; i++) {//단지 나누기

            for (int j = 0; j < m; j++) {

                if (map[i][j] != 0 && visited[i][j] == 0) {

                    cnt += 1;

                    bfs(i, j);

                }

            }

        }

        if (cnt >= 2) {

            cout << year << endl;



            return 0;

        }

        if (cnt == 0) {

            cout << "0" << endl;

            return 0;

        }

        for (int i = 0; i < n; i++) {//얼음 녹이기

            for (int j = 0; j < m; j++) {

                if (map[i][j] != 0) {

                    cmap[i][j] = map[i][j] - melt(i, j);

                    if (cmap[i][j] < 0) cmap[i][j] = 0;

                }

            }

        }

        memcpy(map, cmap, sizeof(map)); //녹은거 반영

        year += 1;

    }
    return 0;

}