#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second

template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

const int INF = (int)1e9 + 7;

#define MAX 300300
int a[MAX], n, q;

void init(void)
{
    cin >> n >> q;
    FOR(i, 1, n)
    cin >> a[i];

    vector<int> values;
    FOR(i, 1, n)
    values.push_back(a[i]);
    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());
    FOR(i, 1, n)
    a[i] = lower_bound(ALL(values), a[i]) - values.begin() + 1;
}

namespace subtask6
{
    bool check(void)
    {
        return true;
    }

#define TREE_MIN false
#define TREE_MAX true

    struct SimpleSegmentTree
    {
        vector<int> lazy;
        int n;
        bool type;

        SimpleSegmentTree(int _n = 0, bool _type = false)
        {
            n = _n;
            type = _type;
            lazy.assign(4 * n + 1, type == TREE_MIN ? INF : -INF);
        }

        void update(int i, int l, int r, int u, int v, int c)
        {
            if (l > v || r < u || l > r || v < u)
                return;
            if (u <= l && r <= v)
            {
                if (type == TREE_MIN)
                    minimize(lazy[i], c);
                else
                    maximize(lazy[i], c);
                return;
            }
            int m = (l + r) >> 1;
            update(2 * i, l, m, u, v, c);
            update(2 * i + 1, m + 1, r, u, v, c);
        }
        void update(int u, int v, int c)
        {
            update(1, 1, n, u, v, c);
        }

        int getValue(int pos) const
        {
            int res = type == TREE_MIN ? INF : -INF;
            int i = 1, l = 1, r = n;
            while (true)
            {
                if (type == TREE_MIN)
                    minimize(res, lazy[i]);
                else
                    maximize(res, lazy[i]);
                if (l == r)
                    return res;
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
        }
    };

    struct SegmentTree
    {
        vector<long long> sum;
        vector<int> lazy, numEnabled;
        int n;

        SegmentTree(int _n = 0)
        {
            n = _n;
            if (n > 0)
            {
                sum.assign(4 * n + 1, 0);
                lazy.assign(4 * n + 1, 0);
                numEnabled.assign(4 * n + 1, 0);
            }
        }

        void pushDown(int i)
        {
            if (lazy[i] == 0)
                return;
            FOR(j, 2 * i, 2 * i + 1)
            {
                sum[j] += 1LL * lazy[i] * numEnabled[j];
                lazy[j] += lazy[i];
            }
            lazy[i] = 0;
        }

        void update(int i, int l, int r, int u, int v, int c)
        {
            if (l > v || r < u || l > r || v < u)
                return;
            if (u <= l && r <= v)
            {
                sum[i] += 1LL * c * numEnabled[i];
                lazy[i] += c;
                return;
            }

            pushDown(i);
            int m = (l + r) >> 1;
            update(2 * i, l, m, u, v, c);
            update(2 * i + 1, m + 1, r, u, v, c);
            sum[i] = sum[2 * i] + sum[2 * i + 1];
        }
        void update(int u, int v, int c)
        {
            update(1, 1, n, u, v, c);
        }

        void setEnable(int pos)
        {
            int i = 1, l = 1, r = n;
            while (true)
            {
                numEnabled[i]++;
                if (l == r)
                    return;

                pushDown(i);
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
        }

        long long getSum(int pos)
        {
            int i = 1, l = 1, r = n;
            long long res = 0;

            while (true)
            {
                if (l == r)
                    return res + sum[i];

                pushDown(i);
                int m = (l + r) >> 1;
                if (pos > m)
                {
                    res += sum[2 * i];
                    i = 2 * i + 1;
                    l = m + 1;
                }
                else
                {
                    i = 2 * i;
                    r = m;
                }
            }
        }
    };

    int next[MAX], pos[MAX];
    int maxBlockedOnY[MAX], minBlockedOnX[MAX];
    vector<int> enable[MAX];
    vector<pair<int, int>> queries[MAX];
    long long answer[MAX];

    void readQuery(void)
    {
        FOR(i, 1, q)
        {
            int u, v;
            cin >> u >> v;
            int minX = u, maxX = v, minY = u, maxY = v;

            queries[maxX].push_back(make_pair(maxY, i));
            if (minY > 1)
                queries[maxX].push_back(make_pair(minY - 1, -i));
            if (minX > 1)
                queries[minX - 1].push_back(make_pair(maxY, -i));
            if (minX > 1 && minY > 1)
                queries[minX - 1].push_back(make_pair(minY - 1, i));
        }
    }

    void calcAnswer(void)
    {
        FOR(i, 1, n)
        pos[a[i]] = n + 1;
        FORD(i, n, 1)
        {
            next[i] = pos[a[i]];
            pos[a[i]] = i;
        }

        SimpleSegmentTree itMin(n, TREE_MIN), itMax(n, TREE_MAX);

        FOR(p1, 1, n)
        if (next[p1] <= n)
        {
            int p2 = next[p1];
            itMax.update(p1, p2 - 1, p1);
            itMin.update(p1 + 1, p2, p2);
        }
        FOR(i, 1, n)
        {
            maxBlockedOnY[i] = max(itMax.getValue(i), 0);
            minBlockedOnX[i] = min(itMin.getValue(i), n + 1);
            enable[maxBlockedOnY[i]].push_back(i);
        }

        //        FOR(i, 1, n) printf("#%d: maxBlockedOnY = %d, minBlockedOnX = %d\n", i, maxBlockedOnY[i], minBlockedOnX[i]);

        SegmentTree myit(n);
        for (int y : enable[0])
            myit.setEnable(y);

        FOR(x, 1, n)
        {
            //            printf("AT %d: add on [%d, %d]\n", x, x, minBlockedOnX[x] - 1);
            myit.update(x, minBlockedOnX[x] - 1, +1);
            for (const pair<int, int> &q : queries[x])
            {
                int y = q.fi, id = q.se;
                long long tmp = myit.getSum(y);
                if (id > 0)
                    answer[id] += tmp;
                else
                    answer[-id] -= tmp;
            }
            //            for (int y : enable[x]) printf("\tEnable %d\n", y);
            for (int y : enable[x])
                myit.setEnable(y);
        }

        FOR(i, 1, q)
        cout << answer[i] << '\n';
    }

    void solve(void)
    {
        readQuery();
        calcAnswer();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("post.inp", "r", stdin);
    freopen("post.out", "w", stdout);

    init();

    if (subtask6::check())
        return subtask6::solve(), 0;
    return 0;
}