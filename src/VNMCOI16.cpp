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

void solve()
{
    cin >> N >> M >> T;
    long long l = 0;
    long long r = min(N, M) / 2 + 1;
    while (r - l > 1)
    {
        long long mid = (l + r) >> 1;
        if (check(mid) == true)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("LATGACH.INP", "r", stdin);
    freopen("LATGACH.OUT", "w", stdout);

    solve();
    return 0;
}