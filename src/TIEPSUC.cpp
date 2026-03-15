#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
const int LOG = 31 - __builtin_clz(mxN);

int N;
int ans[mxN];
vector<int> adj[mxN];
int h[mxN];
int par[mxN][LOG + 1];

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (v != par[u][0])
        {
            par[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

int lca(int u, int v)
{
    if (h[v] > h[u])
    {
        return lca(v, u);
    }
    for (int j = LOG; j >= 0; --j)
    {
        if (h[par[u][j]] >= h[v])
        {
            u = par[u][j];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int j = LOG; j >= 0; --j)
    {
        if (par[u][j] != par[v][j])
        {
            u = par[u][j];
            v = par[v][j];
        }
    }
    return par[u][0];
}

void sfd(int u)
{
    for (int v : adj[u])
    {
        if (v != par[u][0])
        {
            sfd(v);
            ans[u] += ans[v];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("TIEPSUC.INP", "r", stdin);
    freopen("TIEPSUC.OUT", "w", stdout);

    cin >> N;
    for (int i = 1; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= LOG; ++j)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    h[0] = -1;
    for (int i = 1; i < N; ++i)
    {
        int p = lca(i, i + 1);
        ans[i]++;
        ans[i + 1]++;
        ans[p]--;
        ans[par[p][0]]--;
    }
    sfd(1);
    for (int i = 1; i <= N; ++i)
    {
        cout << ans[i] << '\n';
    }
    return 0;
} 