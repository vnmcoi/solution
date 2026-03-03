#include <bits/stdc++.h>
using namespace std;

int N, Q;

struct DisjointSetUnion
{
    int n;
    vector<int> par;
    vector<int> sz;
    vector<long long> sum;

    DisjointSetUnion(int _n) : n(_n)
    {
        par.assign(n + 1, -1);
        sz.assign(n + 1, 1);
        sum.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            sum[i] = i;
        }
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
        sum[v] += sum[u];
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    DisjointSetUnion dsu(N);
    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int u, v;
            cin >> u >> v;
            dsu.merge(u, v);
        }
        else
        {
            int u;
            cin >> u;
            u = dsu.find(u);
            cout << dsu.sum[u] << '\n';
        }
    }
    return 0;
}