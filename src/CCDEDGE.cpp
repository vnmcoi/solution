#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

struct Edge
{
    int u, v;
};

struct Querry
{
    int e, c;
};

int N, M, Q;
Edge adj[mxN];
int ans[mxN];
Querry q[mxN];
bitset<mxN> used;

struct DisjointSetUnion
{
    int n;
    vector<int> par;
    vector<int> sz;

    DisjointSetUnion(int _n) : n(_n)
    {
        par.assign(n + 1, -1);
        sz.assign(n + 1, 1);
    }

    int find(int u)
    {
        return (par[u] == -1 ? u : par[u] = find(par[u]));
    }

    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return false;
        }
        if (sz[u] > sz[v])
        {
            swap(u, v);
        }
        sz[v] += sz[u];
        par[u] = v;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> Q;
    used.set();
    for (int i = 1; i <= M; ++i)
    {
        cin >> adj[i].u >> adj[i].v;
    }
    for (int i = 1; i <= Q; ++i)
    {
        cin >> q[i].e >> q[i].c;
        used[q[i].e] = false;
    }
    DisjointSetUnion dsu(N);
    for (int i = 1; i <= M; ++i)
    {
        if (used[i] == true)
        {
            dsu.merge(adj[i].u, adj[i].v);
        }
    }
    for (int i = Q; i >= 1; --i)
    {
        int c = dsu.find(q[i].c);
        ans[i] = dsu.sz[c];
        dsu.merge(adj[q[i].e].u, adj[q[i].e].v);
    }
    for (int i = 1; i <= Q; ++i)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}