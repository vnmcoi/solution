#include <bits/stdc++.h>
using namespace std;

const int mxP = 1e6 + 5;

int N, P, A, B, R;
int dist[mxP];

void bfs(void)
{
    queue<int> Q;
    N %= P;
    Q.push(N);
    dist[N] = 1;
    while (Q.empty() == false)
    {
        int cur = Q.front();
        Q.pop();
        int x = (cur + A) % P;
        if (dist[x] == 0)
        {
            dist[x] = dist[cur] + 1;
            Q.push(x);
        }
        x = (cur + B) % P;
        if (dist[x] == 0)
        {
            dist[x] = dist[cur] + 1;
            Q.push(x);
        }
        x = (cur + A + B) % P;
        if (dist[x] == 0)
        {
            dist[x] = dist[cur] + 1;
            Q.push(x);
        }
    }
}

void solve()
{
    cin >> N >> P >> A >> B >> R;
    bfs();
    if (dist[R] == 0)
    {
        cout << -1;
    }
    else
    {
        cout << dist[R] - 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("THAYTHE.INP", "r", stdin);
    freopen("THAYTHE.OUT", "w", stdout);

    solve();
    return 0;
}