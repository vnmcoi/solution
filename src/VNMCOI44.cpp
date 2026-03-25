#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, K;
int pref[mxN];

int bs(int x, int l, int r)
{
    int lo = l - 1;
    int hi = r + 1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) >> 1;
        if (pref[mid] - pref[x - 1] <= K)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("NGHENHAC.INP", "r", stdin);
    freopen("NGHENHAC.OUT", "w", stdout);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int pos = bs(i, 1, N);
        ans = max(ans, pos - i + 1);
    }
    cout << ans;
    return 0;
}