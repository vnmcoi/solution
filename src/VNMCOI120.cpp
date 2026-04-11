#include <bits/stdc++.h>
using namespace std;

const int mxN = 7 + 5;

const int moveX[] = {1, -1, -2, -2, -1, 1, 2, 2};
const int moveY[] = {2, 2, 1, -1, -2, -2, -1, 1};

int N, M;
int dist[mxN][mxN];
bool ok = false;

bool check(int x, int y)
{
    return (1 <= x && x <= N && 1 <= y && y <= M && dist[x][y] == 0);
}

void wayslui(int x, int y, int cnt)
{
    if (cnt == N * M)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                cout << dist[i][j] << ' ';
            }
            cout << '\n';
        }
        ok = true;
        return;
    }
    if (ok == true)
    {
        return;
    }
    for (int i = 0; i <= 7; ++i)
    {
        int newX = x + moveX[i];
        int newY = y + moveY[i];
        if (check(newX, newY) == true)
        {
            dist[newX][newY] = cnt + 1;
            wayslui(newX, newY, cnt + 1);
            dist[newX][newY] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dist[1][1] = 1;
    wayslui(1, 1, 1);
    return 0;
}