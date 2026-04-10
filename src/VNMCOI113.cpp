#include <bits/stdc++.h>
using namespace std;

const int mxN = 500 + 5;

const int moveX[] = {1, 0, -1, 0};
const int moveY[] = {0, 1, 0, -1};

int N;
int A[mxN][mxN];
bitset<mxN> vis[mxN];

bool confirm(int x1, int y1, int x2, int y2, int x)
{
    return (1 <= x2 && x2 <= N && 1 <= y2 && y2 <= N && abs(A[x1][y1] - A[x2][y2]) <= x) && vis[x2][y2] == false;
}

bool check(int x)
{
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));
    vis[1][1] = true;
    while (Q.empty() == false)
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i <= 3; ++i)
        {
            int newX = cur.first + moveX[i];
            int newY = cur.second + moveY[i];
            if (confirm(cur.first, cur.second, newX, newY, x) == true)
            {
                vis[newX][newY] = true;
                Q.push(make_pair(newX, newY));
            }
        }
    }
    return vis[N][N];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("TIMDUONG.INP", "r", stdin);
    freopen("TIMDUONG.OUT", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> A[i][j];
        }
    }
    int l = 0;
    int r = 1e6 + 1;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (check(mid) == true)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r;
    return 0;
}