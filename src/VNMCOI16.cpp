#include <bits/stdc++.h>
using namespace std;

long long N, M, T;

bool check(long long x)
{
    if (2 * x > N || 2 * x > M)
    {
        return false;
    }
    return N * M - (N - 2 * x) * (M - 2 * x) <= T;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("LATGACH.INP", "r", stdin);
    freopen("LATGACH.OUT", "w", stdout);

    cin >> N >> M >> T;
    long long lo = 0;
    long long hi = min(N, M) / 2 + 1;
    while (hi - lo > 1)
    {
        long long mid = (lo + hi) >> 1;
        if (check(mid) == true)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    cout << lo;
    return 0;
}