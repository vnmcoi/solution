#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e5 + 5;

int N, Q;

struct querry
{
    int l, r, k, id;
    struct compare
    {
        bool operator()(const querry &a, const querry &b)
        {
            return a.k > b.k;
        }
    };
};

struct value
{
    int val, pos;
    struct compare
    {
        bool operator()(const value &a, const value &b)
        {
            return a.val > b.val;
        }
    };
};

value A[mxN];
querry Querry[mxN];
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

void solve()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i].val;
        A[i].pos = i;
    }
    for (int i = 1; i <= Q; ++i)
    {
        cin >> Querry[i].l >> Querry[i].r >> Querry[i].k;
        Querry[i].id = i;
    }
    sort(A + 1, A + 1 + N, value::compare());
    sort(Querry + 1, Querry + 1 + Q, querry::compare());
    int j = 1;
    SegmentTree it(N);
    for (int i = 1; i <= Q; ++i)
    {
        while (A[j].val > Querry[i].k)
        {
            it.update(1, 1, N, A[j].pos, 1);
            ++j;
        }
        ans[Querry[i].id] = it.querry(1, 1, N, Querry[i].l, Querry[i].r);
    }
    for (int i = 1; i <= Q; ++i)
    {
        cout << ans[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}