#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, M, P;
vector<int> adj[mxN];
int dist[mxN];

int dfs(int u)
{
    for (int v : adj[u])
    {
        if (dist[v] != 0)
        {
            return -1;
        }
        else
        {
            dist[v] = dist[u] + 1;
            return dfs(v);
        }
    }
    return dist[u];
}

void solve()
{
    cin >> N >> M >> P;
    for (int i = 1; i <= N; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    dist[P] = 1;
    int ans = dfs(P);
    if (ans == -1)
    {
        cout << ans;
    }
    else
    {
        cout << ans - 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("CHEFWAR.INP", "r", stdin);
    freopen("CHEFWAR.OUT", "w", stdout);

    solve();
    return 0;
}