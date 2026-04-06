#include <iostream>
#include <vector>
#include <array>
#include <cstdio>

using namespace std;

const int MAXN = 100005;
int N, M, Q, ALL;
int A[MAXN];
int P[MAXN];

int bit_arr[MAXN];
void add_bit(int i, int v)
{
    for (; i <= N; i += i & -i)
        bit_arr[i] ^= v;
}
int query_bit(int i)
{
    int res = 0;
    for (; i > 0; i -= i & -i)
        res ^= bit_arr[i];
    return res;
}

int tree[4 * MAXN][32];
int lz[4 * MAXN];

void apply(int node, int v)
{
    int temp[32];
    for (int x = 0; x <= ALL; ++x)
        temp[x] = tree[node][x ^ v];
    for (int x = 0; x <= ALL; ++x)
        tree[node][x] = temp[x];
    lz[node] ^= v;
}

void pushdown(int node)
{
    if (lz[node])
    {
        apply(2 * node, lz[node]);
        apply(2 * node + 1, lz[node]);
        lz[node] = 0;
    }
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        for (int x = 0; x <= ALL; ++x)
        {
            tree[node][x] = (P[l] == (x ^ ALL)) ? 1 : 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    for (int x = 0; x <= ALL; ++x)
    {
        tree[node][x] = tree[2 * node][x] +
                        ((tree[2 * node][x] % 2 == 0) ? tree[2 * node + 1][x] : tree[2 * node + 1][x ^ ALL]);
    }
}

void update_seg(int node, int l, int r, int ql, int qr, int v)
{
    if (ql <= l && r <= qr)
    {
        apply(node, v);
        return;
    }
    pushdown(node);
    int mid = (l + r) / 2;
    if (ql <= mid)
        update_seg(2 * node, l, mid, ql, qr, v);
    if (qr > mid)
        update_seg(2 * node + 1, mid + 1, r, ql, qr, v);
    for (int x = 0; x <= ALL; ++x)
    {
        tree[node][x] = tree[2 * node][x] +
                        ((tree[2 * node][x] % 2 == 0) ? tree[2 * node + 1][x] : tree[2 * node + 1][x ^ ALL]);
    }
}

struct NodeData
{
    int ans[32];
};

NodeData query_seg(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        NodeData res;
        for (int x = 0; x <= ALL; ++x)
            res.ans[x] = tree[node][x];
        return res;
    }
    pushdown(node);
    int mid = (l + r) / 2;
    if (qr <= mid)
        return query_seg(2 * node, l, mid, ql, qr);
    if (ql > mid)
        return query_seg(2 * node + 1, mid + 1, r, ql, qr);

    NodeData L = query_seg(2 * node, l, mid, ql, qr);
    NodeData R = query_seg(2 * node + 1, mid + 1, r, ql, qr);
    NodeData res;
    for (int x = 0; x <= ALL; ++x)
    {
        res.ans[x] = L.ans[x] + ((L.ans[x] % 2 == 0) ? R.ans[x] : R.ans[x ^ ALL]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("PHUTHUY.INP", "r"))
    {
        freopen("PHUTHUY.INP", "r", stdin);
        freopen("PHUTHUY.OUT", "w", stdout);
    }

    if (!(cin >> N >> M >> Q))
        return 0;
    ALL = (1 << M) - 1;

    for (int i = 1; i <= N; ++i)
    {
        int k;
        cin >> k;
        int mask = 0;
        for (int j = 0; j < k; ++j)
        {
            int spell;
            cin >> spell;
            mask |= (1 << (spell - 1));
        }
        A[i] = mask;
        add_bit(i, A[i]);
        P[i] = P[i - 1] ^ A[i];
    }

    build(1, 1, N);

    for (int q = 0; q < Q; ++q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, l;
            cin >> idx >> l;
            int mask = 0;
            for (int j = 0; j < l; ++j)
            {
                int spell;
                cin >> spell;
                mask |= (1 << (spell - 1));
            }
            int v = A[idx] ^ mask;
            if (v != 0)
            {
                A[idx] = mask;
                add_bit(idx, v);
                update_seg(1, 1, N, idx, N, v);
            }
        }
        else
        {
            int L, R;
            cin >> L >> R;
            int P_L_minus_1 = query_bit(L - 1);
            int P_R = query_bit(R);

            int diff = P_L_minus_1 ^ P_R;
            if (diff != 0 && diff != ALL)
            {
                cout << -1 << "\n";
            }
            else
            {
                NodeData res = query_seg(1, 1, N, L, R);
                int ans = res.ans[P_L_minus_1];
                if (ans == 0)
                {
                    cout << -1 << "\n";
                }
                else
                {
                    cout << ans << "\n";
                }
            }
        }
    }
    return 0;
}