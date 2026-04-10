#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N;
int A[mxN];

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
};

int compress(const vector<int> &a, int x)
{
    return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> raw;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        raw.push_back(A[i]);
    }
    sort(raw.begin(), raw.end());
    raw.erase(unique(raw.begin(), raw.end()), raw.end());
    FenwickTree bit(N);
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x = compress(raw, A[i]);
        ans += bit.get(N) - bit.get(x);
        bit.update(x, 1);
    }
    cout << ans;
    return 0;
}