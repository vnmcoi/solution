#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define fi first
#define se second

#define MAX 220797
int a[MAX], n;

void process(void)
{
    scanf("%d", &n);
    FOR(i, 1, n)
    scanf("%d", &a[i]);

    set<int> pos;
    priority_queue<pair<int, int>> maxVal;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minVal;

    FOR(i, 1, n)
    {
        pos.insert(i);
        maxVal.push(make_pair(a[i], i));
        minVal.push(make_pair(a[i], i));
    }

    int res = 0;

    while (true)
    {
        while (!maxVal.empty() && pos.find(maxVal.top().se) == pos.end())
            maxVal.pop();
        while (!minVal.empty() && pos.find(minVal.top().se) == pos.end())
            minVal.pop();
        if (minVal.empty() || maxVal.empty())
            break;

        res++;
        int L = maxVal.top().se;
        int R = minVal.top().se;
        if (L > R)
            swap(L, R);

        while (!pos.empty())
        {
            __typeof(pos.begin()) it = pos.lower_bound(L);
            if (it == pos.end() || *it > R)
                break;
            pos.erase(it);
        }
    }

    cout << res << "\n";
}

int main(void)
{
#ifdef ONLINE_JUDGE
    freopen("lab.inp", "r", stdin);
    freopen("lab.out", "w", stdout);
#endif // ONLINE_JUDGE

    process();
    return 0;
}
