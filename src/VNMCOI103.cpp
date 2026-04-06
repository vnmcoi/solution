#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()

#define prev T120HLE
#define next HLE02T1

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

struct SegmentTree
{
    vector<int> lazy, cnt;
    vector<long long> sum;
    int n;

    SegmentTree(int _n = 0)
    {
        n = _n;
        if (n == 0)
            return;

        lazy.assign(4 * n + 7, 0);
        cnt.assign(4 * n + 7, 0);
        sum.assign(4 * n + 7, 0);
    }

    void pushDown(int i)
    {
        if (lazy[i] == 0)
            return;
        FOR(j, 2 * i, 2 * i + 1)
        {
            sum[j] += 1LL * lazy[i] * cnt[j];
            lazy[j] += lazy[i];
        }
        lazy[i] = 0;
    }

    void changeType(int pos, int delta)
    {
        int i = 1, l = 1, r = n;
        while (l < r)
        {
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

        cnt[i] = delta > 0 ? +1 : 0;
        sum[i] = 0;
        while (i > 1)
        {
            i >>= 1;
            sum[i] = sum[2 * i] + sum[2 * i + 1];
            cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
        }
    }

    void update(int i, int l, int r, int u, int v, int delta)
    {
        if (l > v || r < u || l > r || v < u)
            return;
        if (u <= l && r <= v)
        {
            sum[i] += 1LL * cnt[i] * delta;
            lazy[i] += delta;
            return;
        }

        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, delta);
        update(2 * i + 1, m + 1, r, u, v, delta);
        sum[i] = sum[2 * i] + sum[2 * i + 1];
    }
    void update(int u, int v, int delta)
    {
        update(1, 1, n, u, v, delta);
    }

    long long calcSum(void) const
    {
        return sum[1];
    }
};

#define MAX 400400
int n, a[MAX];
long long lowSum, highSum, sum[MAX];
long long lowAns[MAX], highAns[MAX];
vector<pair<long long, int>> sumAndPos;
int pos[MAX];

void init(void)
{
    scanf("%d%lld%lld", &n, &lowSum, &highSum);
    lowSum--;
    FOR(i, 1, n)
    scanf("%d", &a[i]);
    FOR(i, 1, n)
    a[n + i] = a[i];
    FOR(i, 1, 2 * n)
    sum[i] = sum[i - 1] + a[i];
}

void solve(long long maxSum, long long ans[])
{
    sumAndPos.clear();
    FOR(i, 0, 2 * n - 1)
    sumAndPos.push_back(make_pair(sum[i], i));
    sort(ALL(sumAndPos));
    REP(i, sumAndPos.size())
    pos[sumAndPos[i].se] = i + 1;

    SegmentTree myit(sumAndPos.size());

    FORD(r, 2 * n - 2, 1)
    {
        if (0 <= r && r <= n - 1)
            myit.changeType(pos[r], -1);
        if (0 <= r - (n - 1) && r - (n - 1) <= n - 1)
            myit.changeType(pos[r - (n - 1)], +1);

        int tmp = lower_bound(ALL(sumAndPos), make_pair(sum[r] - maxSum, -1)) - sumAndPos.begin() + 1;
        myit.update(tmp, sumAndPos.size(), +1);

        ans[r] = myit.calcSum();
    }

    //    FORD(r, 2 * n - 2, 1) {
    //        FOR(l, max(0, r - (n - 1)), min(r - 1, n - 1)) if (sum[l] >= sum[r] - maxSum) cnt[l]++;
    //        FOR(l, max(0, r - (n - 1)), min(r - 1, n - 1)) ans[r] += cnt[l];
    //    }
    FOR(i, 1, n)
    ans[i] += ans[n + i];
}

void process(void)
{
    solve(highSum, highAns);
    solve(lowSum, lowAns);

    FOR(i, 1, n)
    printf("%lld ", highAns[i] - lowAns[i]);
    printf("\n");
}

int main(void)
{
#ifdef ONLINE_JUDGE
    freopen("cgame.inp", "r", stdin);
    freopen("cgame.out", "w", stdout);
#endif // ONLINE_JUDGE

    init();
    process();
    return 0;
}
