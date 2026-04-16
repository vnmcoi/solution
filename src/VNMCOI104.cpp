#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;
const int MOD = 1e3 + 7;

int N, Q;
int f[MOD];

struct FenwickTree
{
    int n;
    vector<long long> add;
    vector<long long> mul;

    FenwickTree(int _n) : n(_n)
    {
        add.assign(n + 1, 0);
        mul.assign(n + 1, 0);
    }

    void update(int x, int v, vector<long long> &bit)
    {
        for (; x <= n; x += x & -x)
        {
            bit[x] += v;
        }
    }

    long long get(int x, vector<long long> &bit)
    {
        long long res = 0;
        for (; x >= 1; x -= x & -x)
        {
            res += bit[x];
        }
        return res;
    }

    void updateRange(int l, int r, long long v)
    {
        update(l, v, add);
        update(r + 1, -v, add);
        update(l, v * l, mul);
        update(r + 1, -v * (r + 1), mul);
    }

    long long sum(int x)
    {
        return (x + 1) * get(x, add) - get(x, mul);
    }

    long long querry(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

int init()
{
    f[1] = f[2] = 1;
    int i = 3;
    while (true)
    {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
        if (i > 3 && f[i] == 1 && f[i - 1] == 1 && f[i - 2] == 0)
        {
            return i;
        }
        ++i;
    }
}

void solve()
{
    cin >> N >> Q;
    int m = init();
    m -= 2;
    FenwickTree bit(N);
    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r;
            long long k;
            cin >> l >> r >> k;
            bit.updateRange(l, r, f[k % m]);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << bit.querry(l, r) << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("BIENDOI.INP", "r", stdin);
    freopen("BIENDOI.OUT", "w", stdout);

    solve();
    return 0;
}