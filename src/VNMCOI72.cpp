#include <bits/stdc++.h>
using namespace std;

const int mxN = 10 + 5;

int N;
int A[mxN][mxN];
bool vis[mxN];
int ans = 1e9;

void wayslui(int u, int val, int cnt)
{
    if (val > ans)
    {
        return;
    }
    if (cnt == N)
    {
        ans = min(ans, val + A[u][1]);
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            val += A[u][i];
            wayslui(i, val, cnt + 1);
            vis[i] = false;
            val -= A[u][i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> A[i][j];
        }
    }
    vis[1] = true;
    wayslui(1, 0, 1);
    cout << ans;
    return 0;
}