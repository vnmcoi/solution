#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N;
int A[mxN];
int pos[mxN];

struct FenwickTree
{
    int n;
    vector<int> bit;

    FenwickTree(int _n) : n(_n)
    {
        bit.assign(n + 1, 0);
    }

    void update(int x, int v)
    {
        for (; x <= n; x += x & -x)
        {
            bit[x] += v;
        }
    }

    int get(int x)
    {
        int res = 0;
        for (; x >= 1; x -= x & -x)
        {
            res += bit[x];
        }
        return res;
    }

    int sum(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};

void solve()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        pos[A[i]] = i;
    }
    FenwickTree bit(N);
    for (int i = 1; i <= N; ++i)
    {
        bit.update(i, 1);
    }
    int ans = 0;
    int L = 1, R = N;
    for (int i = 1; i <= N; ++i)
    {
        if (i & 1)
        {
            int x = pos[L];
            cout << bit.sum(1, x) - 1 << '\n';
            bit.update(x, -1);
            ++L;
        }
        else
        {
            int x = pos[R];
            cout << bit.sum(x, N) - 1 << '\n';
            bit.update(x, -1);
            --R;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("SAPXEP.INP", "r", stdin);
    freopen("SAPXEP.OUT", "w", stdout);

    solve();
    return 0;
}