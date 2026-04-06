#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5;

int N, K;

struct DisjointSetUnion
{
    int n;
    vector<int> sz;
    vector<int> par;

    DisjointSetUnion(int _n) : n(_n)
    {
        sz.assign(n + 1, 1);
        par.assign(n + 1, -1);
    }

    int find(int u)
    {
        return par[u] == -1 ? u : par[u] = find(par[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        par[u] = v;
        sz[v] += sz[u];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("BANDO.INP", "r", stdin);
    freopen("BANDO.OUT", "w", stdout);
    cin >> N >> K;
    DisjointSetUnion dsu(N);
    int l = 0, r = N;
    for (int i = 1; i <= K; ++i)
    {
        int x;
        cin >> x;
        x = dsu.find(x);
        cerr << abs(x - l) << ' ' << abs(r - x) << '\n';
        if (abs(x - l) <= abs(r - x))
        {
            for (int j = l; j < x; ++j)
            {
                dsu.merge(j, x + (x - j));
            }
            l = x;
        }
        else
        {
            for (int j = r; j > x; --j)
            {
                dsu.merge(j, x - (j - x));
            }
            r = x;
        }
    }
    cout << r - l + 1 << '\n';
    for (int i = l; i <= r; ++i)
    {
        cout << dsu.sz[i] << ' ';
    }
    return 0;
}