#include <iostream>
#include <stack>
using namespace std;

int map[25][25];

typedef struct point {
    int x;
    int y;
}Point;

Point arround[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int main()
{
    int size;
    stack<Point> s;
    cin >> size;

    string str;
    for (int i = 0; i < size; i++)
    {
        cin >> str;
        for (int j = 0; j < size; j++)
        {
            if (str[j] == '0') map[i][j] = 0;
            else map[i][j] = -1;
        }
    }

    Point current, temp;
    int cnt = 1;
    int Home_cnt[700] = { 0, };
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (map[i][j] == -1)
            {
                s.push({j, i});
                map[i][j] = cnt;
                Home_cnt[cnt]++;
                while (!s.empty())
                {
                    current = s.top();
                    s.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        temp.x = current.x + arround[k].x;
                        temp.y = current.y + arround[k].y;
                        if (temp.x >= 0 && temp.x < size && temp.y >= 0 && temp.y < size)
                        {
                            if (map[temp.y][temp.x] == -1)
                            {
                                map[temp.y][temp.x] = cnt;
                                Home_cnt[cnt]++;
                                s.push(temp);
                            }
                        }
                    }
                }
                cnt++;
            }
        }
    }

    cout << cnt - 1 << "\n";
    int min = 1000, idx;
    for (int i = 1; i < cnt; i++)
    {
        for (int j = 1; j < cnt; j++)
        {
            if (min > Home_cnt[j] && Home_cnt[j] != 0)
            {
                min = Home_cnt[j];
                idx = j;
            }
        }
        if (min != 1000)
        {
            cout << min << "\n";
            Home_cnt[idx] = 0;
            min = 1000;
        }
    }


        return 0;
}