#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

struct Querry
{
    int l, r, k, id;
    struct compare
    {
        bool operator()(const Querry &a, const Querry &b)
        {
            return a.k > b.k;
        }
    };
};

struct Value
{
    int val, pos;
    struct compare
    {
        bool operator()(const Value &a, const Value &b)
        {
            return a.val > b.val;
        }
    };
};

int N, Q;
Value a[mxN];
Querry q[mxN];
int ans[mxN];

struct SegmentTree
{
    int n;
    vector<int> it;

    SegmentTree(int _n) : n(_n)
    {
        it.assign((n << 2) + 1, 0);
    }

    void update(int id, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            it[id] += val;
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
        {
            update(id << 1, l, mid, pos, val);
        }
        else
        {
            update(id << 1 | 1, mid + 1, r, pos, val);
        }

        it[id] = it[id << 1] + it[id << 1 | 1];
    }

    int querry(int id, int l, int r, int a, int b)
    {
        if (b < l || r < a)
        {
            return 0;
        }
        if (a <= l && r <= b)
        {
            return it[id];
        }

        int mid = (l + r) >> 1;

        return querry(id << 1, l, mid, a, b) + querry(id << 1 | 1, mid + 1, r, a, b);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i].val;
        a[i].pos = i;
    }
    for (int i = 1; i <= Q; ++i)
    {
        cin >> q[i].l >> q[i].r >> q[i].k;
        q[i].id = i;
    }
    sort(a + 1, a + 1 + N, Value::compare());
    sort(q + 1, q + 1 + Q, Querry::compare());
    int j = 1;
    SegmentTree it(N);
    for (int i = 1; i <= Q; ++i)
    {
        while (a[j].val > q[i].k)
        {
            it.update(1, 1, N, a[j].pos, 1);
            ++j;
        }
        ans[q[i].id] = it.querry(1, 1, N, 1, q[i].r) - it.querry(1, 1, N, 1, q[i].l - 1);
    }
    for (int i = 1; i <= Q; ++i)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}