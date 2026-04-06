/**
 * Bai nay chi can mot nhat xet ve phep modulo. Xem video tai: https://youtube.com/watch?v=_mGYTg4diQ4
 **/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define fi first
#define se second

#define MAX 200200
#define LOG 18

int numNode, numQuery, value[MAX];
vector<int> adj[MAX];

void loadTree(void)
{
    scanf("%d%d", &numNode, &numQuery);
    FOR(i, 1, numNode)
    scanf("%d", &value[i]);
    REP(faker, numNode - 1)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

namespace subtask1
{
    bool check(void)
    {
        return numNode <= 5000 && numQuery <= 5000;
    }

    int high[MAX], par[MAX];

    void dfs(int u)
    {
        for (int v : adj[u])
            if (v != par[u])
            {
                par[v] = u;
                high[v] = high[u] + 1;
                dfs(v);
            }
    }

    void query(int u, int v, int w)
    {
        while (high[u] > high[v])
        {
            value[u] %= w;
            u = par[u];
        }
        while (high[v] > high[u])
        {
            value[v] %= w;
            v = par[v];
        }
        if (u == v)
        {
            value[u] %= w;
            return;
        }

        while (u != v)
        {
            value[u] %= w;
            u = par[u];
            value[v] %= w;
            v = par[v];
        }
        value[u] %= w;
    }

    void solve(void)
    {
        high[0] = -1;
        dfs(1);

        FOR(i, 1, numQuery)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            query(u, v, w);
            long long sum = 0;
            FOR(u, 1, numNode)
            sum += value[u] % i;
            printf("%lld\n", sum);
        }
    }
}

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        if (n > 0)
            bit.assign(n + 1, 0);
    }

    void update(int x, int d)
    {
        for (; x <= n; x += x & -x)
            bit[x] += d;
    }
    long long get(int x) const
    {
        long long res = 0;
        for (; x >= 1; x &= x - 1)
            res += bit[x];
        return res;
    }

    long long sumRange(int l, int r) const
    {
        if (l > r)
            return 0;
        else
            return l == 1 ? get(r) : get(r) - get(l - 1);
    }
};

struct SegmentTree
{
    vector<pair<int, int>> tree;
    int n;

    void init(int i, int l, int r)
    {
        if (l == r)
        {
            tree[i] = make_pair(0, r);
            return;
        }
        int m = (l + r) >> 1;
        init(2 * i, l, m);
        init(2 * i + 1, m + 1, r);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    SegmentTree(int _n = 0)
    {
        n = _n;
        if (n > 0)
        {
            tree.assign(4 * n + 7, make_pair(0, 0));
            init(1, 1, n);
        }
    }

    void setValue(int pos, int value)
    {
        int i = 1, l = 1, r = n;
        while (l < r)
        {
            int m = (l + r) >> 1;
            if (pos > m)
            {
                i = 2 * i + 1;
                l = m + 1;
            }
            else
            {
                i = 2 * i;
                r = m;
            }
        }

        tree[i] = make_pair(value, pos);
        while (i > 1)
        {
            i >>= 1;
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    pair<int, int> getMax(int i, int l, int r, int u, int v) const
    {
        if (l > v || r < u || l > r || v < u)
            return make_pair(-1, 0);
        if (u <= l && r <= v)
            return tree[i];
        int m = (l + r) >> 1;
        pair<int, int> L = getMax(2 * i, l, m, u, v);
        pair<int, int> R = getMax(2 * i + 1, m + 1, r, u, v);
        return max(L, R);
    }

    pair<int, int> getMax(int u, int v) const
    {
        return getMax(1, 1, n, u, v);
    }
};

namespace subtask4
{
    bool check(void)
    {
        FOR(u, 1, numNode - 1)
        {
            bool found = false;
            for (int v : adj[u])
                if (v == u + 1)
                {
                    found = true;
                    break;
                }
            if (!found)
                return false;
        }
        return true;
    }

    FenwickTree cnt, sum;
    SegmentTree myit;

    void updateValue(int value, int delta)
    {
        if (value == 0)
            return;
        cnt.update(value, delta);
        sum.update(value, delta * value);
    }

    long long sumModulo(int p)
    {
        long long res = 0;
        for (int k = 0; 1LL * k * p <= MAX; k++)
        {
            int low = max(1, k * p);
            int high = min(MAX, (k + 1) * p - 1);
            res += sum.sumRange(low, high) - cnt.sumRange(low, high) * k * p;
        }
        return res;
    }

    void query(int u, int v, int w)
    {
        if (u > v)
            swap(u, v);

        while (true)
        {
            pair<int, int> tmp = myit.getMax(u, v);
            if (tmp.fi < w)
                break;
            updateValue(tmp.fi, -1);
            tmp.fi %= w;
            updateValue(tmp.fi, +1);
            myit.setValue(tmp.se, tmp.fi);
        }
    }

    void solve(void)
    {
        myit = SegmentTree(numNode);
        cnt = FenwickTree(MAX);
        sum = FenwickTree(MAX);

        FOR(i, 1, numNode)
        {
            myit.setValue(i, value[i]);
            updateValue(value[i], +1);
        }

        FOR(i, 1, numQuery)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            query(u, v, w);
            printf("%lld\n", sumModulo(i));
        }
    }
}

namespace subtask5
{
    int par[MAX][LOG + 1], high[MAX], treeSize[MAX];
    int heavyChild[MAX], lightParent[MAX], pos[MAX], cntDFS;

    SegmentTree myit;
    FenwickTree cnt, sum;

    void updateValue(int value, int delta)
    {
        if (value == 0)
            return;
        cnt.update(value, delta);
        sum.update(value, delta * value);
    }

    long long sumModulo(int p)
    {
        long long res = 0;
        for (int k = 0; 1LL * k * p <= MAX; k++)
        {
            int low = max(1, k * p);
            int high = min(MAX, (k + 1) * p - 1);
            res += sum.sumRange(low, high) - cnt.sumRange(low, high) * k * p;
        }
        return res;
    }

    void preDFS(int u)
    {
        treeSize[u] = 1;
        for (int v : adj[u])
            if (v != par[u][0])
            {
                par[v][0] = u;
                high[v] = high[u] + 1;
                preDFS(v);
                treeSize[u] += treeSize[v];
            }
    }

    void hldDFS(int u)
    {
        pos[u] = ++cntDFS;

        for (int v : adj[u])
            if (v != par[u][0])
                if (heavyChild[u] < 1 || treeSize[heavyChild[u]] < treeSize[v])
                    heavyChild[u] = v;
        if (heavyChild[u] < 1)
            return;

        int v = heavyChild[u];
        lightParent[v] = lightParent[u];
        hldDFS(v);

        for (int v : adj[u])
            if (v != par[u][0] && v != heavyChild[u])
            {
                lightParent[v] = v;
                hldDFS(v);
            }
    }

    int lck(int u, int v)
    {
        if (high[v] > high[u])
            swap(u, v);
        FORD(i, LOG, 0)
        if (high[par[u][i]] >= high[v])
            u = par[u][i];
        if (u == v)
            return u;

        FORD(i, LOG, 0)
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
        return par[u][0];
    }

    void updatePath(int u, int p, int mod)
    {
        while (true)
        {
            int v = lightParent[u];
            if (high[v] < high[p])
                v = p;

            int fr = pos[v], to = pos[u];
            while (true)
            {
                pair<int, int> tmp = myit.getMax(fr, to);
                if (tmp.fi < mod)
                    break;
                //                printf("pos %d: %d -> %d\n", tmp.se, tmp.fi, tmp.fi % mod);
                updateValue(tmp.fi, -1);
                tmp.fi %= mod;
                updateValue(tmp.fi, +1);
                myit.setValue(tmp.se, tmp.fi);
            }

            if (v == p)
                break;
            u = par[v][0];
        }
    }

    void query(int u, int v, int w)
    {
        int p = lck(u, v);
        updatePath(u, p, w);
        updatePath(v, p, w);
    }

    void solve(void)
    {
        high[0] = -1;
        preDFS(1);
        FOR(j, 1, LOG)
        FOR(i, 1, numNode)
        par[i][j] = par[par[i][j - 1]][j - 1];
        lightParent[1] = 1;
        hldDFS(1);

        //        FOR(i, 1, numNode) printf("Node %d: pos = %d, child = %d, parent = %d\n", i, pos[i], heavyChild[i], lightParent[i]);

        myit = SegmentTree(numNode);
        cnt = FenwickTree(MAX);
        sum = FenwickTree(MAX);

        FOR(i, 1, numNode)
        {
            myit.setValue(pos[i], value[i]);
            updateValue(value[i], +1);
        }

        FOR(i, 1, numQuery)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            query(u, v, w);
            printf("%lld\n", sumModulo(i));
        }
    }
}

int main(void)
{

    loadTree();

    subtask5::solve();
    return 0;
}