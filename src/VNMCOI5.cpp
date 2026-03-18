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
        if (dist[v] == 0)
        {
            dist[v] = dist[u] + 1;
            return dfs(v);
        }
        else
        {
            return -1;
        }
    }
    return dist[u];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("CHEFWAR.INP", "r", stdin);
    freopen("CHEFWAR.OUT", "w", stdout);

    cin >> N >> M >> P;
    for (int i = 1; i <= N; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    cout << dfs(P);
    return 0;
}