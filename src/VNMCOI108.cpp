#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
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

struct Query
{
    int type, maxWeight, numTypePerBag, numBag, id;

    Query()
    {
        type = maxWeight = numTypePerBag = numBag = 0;
    }

    void input(int id)
    {
        scanf("%d%d%d", &type, &maxWeight, &numTypePerBag);
        if (type == 1)
            scanf("%d", &numBag);
        this->id = id;
    }
};

#define MAX 100100
const long long INF = (long long)1e18 + 7LL;

int numType, numQuery, limit[MAX], weight[MAX], answer[MAX];
Query queries[MAX];

void init(void)
{
    scanf("%d%d", &numType, &numQuery);
    FOR(i, 1, numType)
    scanf("%d", &weight[i]);
    FOR(i, 1, numType)
    scanf("%d", &limit[i]);
    FOR(i, 1, numQuery)
    queries[i].input(i);
}

namespace subtask1
{
    bool check(void)
    {
        FOR(i, 1, numType)
        if (limit[i] != 1) return false;
        return true;
    }

    long long sumWeight[MAX];

    bool ok(int maxWeight, int numTypePerBag, int numBag)
    {
        if (1LL * numTypePerBag * numBag > numType)
            return false;
        int tmp = numTypePerBag * numBag;
        return sumWeight[tmp] <= maxWeight;
    }

    int getMaxBag(int maxWeight, int numTypePerBag)
    {
        int L = 0, R = maxWeight;
        while (L < R)
        {
            int M = R - L == 1 ? R : (L + R) >> 1;
            if (ok(maxWeight, numTypePerBag, M))
                L = M;
            else
                R = M - 1;
        }
        return R;
    }

    void solve(void)
    {
        sort(weight + 1, weight + numType + 1);
        FOR(i, 1, numType)
        sumWeight[i] = sumWeight[i - 1] + weight[i];
        FOR(i, 1, numQuery)
        {
            if (queries[i].type == 1)
                printf("%d\n", ok(queries[i].maxWeight, queries[i].numTypePerBag, queries[i].numBag) ? 1 : 0);
            else
                printf("%d\n", getMaxBag(queries[i].maxWeight, queries[i].numTypePerBag));
        }
    }
}

namespace subtask3
{
    bool check(void)
    {
        return numType <= 1000 && numQuery <= 1000;
    }

    bool ok(int maxWeight, int numTypePerBag, int numBag)
    {
        long long need = 1LL * numTypePerBag * numBag;
        FOR(i, 1, numType)
        {
            int tmp = min(need, 1LL * min(numBag, limit[i]));
            if (1LL * tmp * weight[i] > maxWeight)
                return false;
            need -= tmp;
            maxWeight -= tmp * weight[i];
        }

        return need <= 0 && maxWeight >= 0;
    }

    int getMaxBag(int maxWeight, int numTypePerBag)
    {
        int L = 0, R = maxWeight;
        while (L < R)
        {
            int M = R - L == 1 ? R : (L + R) >> 1;
            if (ok(maxWeight, numTypePerBag, M))
                L = M;
            else
                R = M - 1;
        }
        return R;
    }

    void solve(void)
    {
        vector<pair<int, int>> items;
        FOR(i, 1, numType)
        items.push_back(make_pair(weight[i], limit[i]));
        sort(ALL(items));

        FOR(i, 1, numType)
        {
            weight[i] = items[i - 1].fi;
            limit[i] = items[i - 1].se;
        }

        FOR(i, 1, numQuery)
        {
            if (queries[i].type == 1)
                printf("%d\n", ok(queries[i].maxWeight, queries[i].numTypePerBag, queries[i].numBag) ? 1 : 0);
            else
                printf("%d\n", getMaxBag(queries[i].maxWeight, queries[i].numTypePerBag));
        }
    }
}

struct SegmentTree
{
    vector<int> unlimitedCount;
    vector<long long> unlimitedSumWeight, limitedSumWeight, limitedSumLimit;
    int n;

    SegmentTree()
    {
        n = 0;
    }
    SegmentTree(int _n, int weight[])
    {
        n = _n;
        unlimitedCount.assign(4 * n + 7, 0);
        unlimitedSumWeight.assign(4 * n + 7, 0);
        limitedSumWeight.assign(4 * n + 7, 0);
        limitedSumLimit.assign(4 * n + 7, 0);

        init(1, 1, n, weight);
    }

    void init(int i, int l, int r, int weight[])
    {
        if (l == r)
        {
            unlimitedCount[i] = 1;
            unlimitedSumWeight[i] = weight[r];
            return;
        }

        int m = (l + r) >> 1;
        init(2 * i, l, m, weight);
        init(2 * i + 1, m + 1, r, weight);
        unlimitedCount[i] = unlimitedCount[2 * i] + unlimitedCount[2 * i + 1];
        unlimitedSumWeight[i] = unlimitedSumWeight[2 * i] + unlimitedSumWeight[2 * i + 1];
    }

    void setLimited(int pos, int limit, int weight)
    {
        int i = 1, l = 1, r = n;
        while (true)
        {
            unlimitedCount[i]--;
            unlimitedSumWeight[i] -= weight;
            limitedSumLimit[i] += limit;
            limitedSumWeight[i] += 1LL * limit * weight;

            if (l == r)
                return;
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

    long long getSumWeight(int numTypePerBag, int numBag)
    {
        long long need = 1LL * numTypePerBag * numBag;
        if (need > 1LL * unlimitedCount[1] * numBag + limitedSumLimit[1])
            return INF;

        int i = 1, l = 1, r = n;
        long long res = 0;
        while (true)
        {
            if (need == 0)
                return res;
            if (l == r)
            {
                if (unlimitedCount[i] > 0)
                    return res + need * unlimitedSumWeight[i];
                else
                    return res + limitedSumWeight[i] / limitedSumLimit[i] * need;
            }

            int m = (l + r) >> 1;
            long long canLeft = 1LL * unlimitedCount[2 * i] * numBag + limitedSumLimit[2 * i];
            if (need >= canLeft)
            {
                res += 1LL * unlimitedSumWeight[2 * i] * numBag + limitedSumWeight[2 * i];
                need -= canLeft;
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

namespace subtask4
{
    bool check(void)
    {
        FOR(i, 1, numQuery)
        if (queries[i].type != 1) return false;
        return true;
    }

    int queryID[MAX], typeID[MAX];
    bool CompareQuery(const int &x, const int &y)
    {
        return queries[x].numBag < queries[y].numBag;
    }
    bool CompareType(const int &x, const int &y)
    {
        return limit[x] < limit[y];
    }

    void solve(void)
    {
        vector<pair<int, int>> items;
        FOR(i, 1, numType)
        items.push_back(make_pair(weight[i], limit[i]));
        sort(ALL(items));

        FOR(i, 1, numType)
        {
            weight[i] = items[i - 1].fi;
            limit[i] = items[i - 1].se;
        }

        FOR(i, 1, numQuery)
        queryID[i] = i;
        sort(queryID + 1, queryID + numQuery + 1, CompareQuery);
        FOR(i, 1, numType)
        typeID[i] = i;
        sort(typeID + 1, typeID + numType + 1, CompareType);

        SegmentTree myit(numType, weight);

        int j = 1;
        FOR(i, 1, numQuery)
        {
            int qid = queryID[i];
            while (j <= numType)
            {
                int tid = typeID[j];
                if (limit[tid] > queries[qid].numBag)
                    break;
                myit.setLimited(tid, limit[tid], weight[tid]);
                j++;
            }

            answer[qid] = myit.getSumWeight(queries[qid].numTypePerBag, queries[qid].numBag) <= queries[qid].maxWeight ? 1 : 0;
        }

        FOR(i, 1, numQuery)
        printf("%d\n", answer[i]);
    }
}

namespace subtask5
{
    bool check(void)
    {
        return true;
    }

    int queryID[MAX], typeID[MAX], low[MAX], high[MAX];
    bool CompareQuery(const int &x, const int &y)
    {
        return queries[x].numBag < queries[y].numBag;
    }
    bool CompareType(const int &x, const int &y)
    {
        return limit[x] < limit[y];
    }

    void solve(void)
    {
        vector<pair<int, int>> items;
        FOR(i, 1, numType)
        items.push_back(make_pair(weight[i], limit[i]));
        sort(ALL(items));

        FOR(i, 1, numType)
        {
            weight[i] = items[i - 1].fi;
            limit[i] = items[i - 1].se;
        }

        FOR(i, 1, numType)
        typeID[i] = i;
        sort(typeID + 1, typeID + numType + 1, CompareType);

        FOR(i, 1, numQuery)
        {
            if (queries[i].type == 2)
            {
                low[i] = 0, high[i] = queries[i].maxWeight;
            }
            else
            {
                low[i] = queries[i].numBag - 1, high[i] = queries[i].numBag;
            }
        }

        while (true)
        {
            vector<pair<int, int>> checks;
            FOR(i, 1, numQuery)
            if (low[i] < high[i])
            {
                int mid = high[i] - low[i] == 1 ? high[i] : (low[i] + high[i]) >> 1;
                checks.push_back(make_pair(mid, i));
            }
            if (checks.empty())
                break;

            SegmentTree myit(numType, weight);
            int j = 1;

            sort(ALL(checks));
            for (const pair<int, int> &p : checks)
            {
                int numBag = p.fi, qid = p.se;

                while (j <= numType)
                {
                    int tid = typeID[j];
                    if (limit[tid] > numBag)
                        break;
                    myit.setLimited(tid, limit[tid], weight[tid]);
                    j++;
                }

                bool ok = myit.getSumWeight(queries[qid].numTypePerBag, numBag) <= queries[qid].maxWeight;
                //                printf("CHECK #%d mid = %d -> %s\n", qid, numBag, ok ? "TRUE" : "FALSE");
                if (ok)
                    low[qid] = numBag;
                else
                    high[qid] = numBag - 1;
            }
        }

        FOR(i, 1, numQuery)
        printf("%d\n", queries[i].type == 1 ? high[i] == queries[i].numBag : high[i]);
    }
}

int main(void)
{
    freopen("gift.inp", "r", stdin);
    freopen("gift.out", "w", stdout);

    init();

    if (subtask1::check())
        return subtask1::solve(), 0;
    if (subtask3::check())
        return subtask3::solve(), 0;
    if (subtask4::check())
        return subtask4::solve(), 0;
    if (subtask5::check())
        return subtask5::solve(), 0;

    subtask5::solve();
    return 0;
}