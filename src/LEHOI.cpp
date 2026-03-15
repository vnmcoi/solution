#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5;

int N, q;
int A[mxN];
long long dp[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("LEHOI.INP", "r", stdin);
    freopen("LEHOI.OUT", "w", stdout);

    cin >> N >> q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + N);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (i - 1 >= 0)
        {
            dp[i] = min(dp[i], dp[i - 1] + 1LL * A[i] * (100 - q) / 100);
        }
        if (i - 2 >= 0)
        {
            dp[i] = min(dp[i], dp[i - 2] + 1LL * (A[i - 1] + A[i]) * (100 - q) / 100);
        }
        if (i - 3 >= 0)
        {
            dp[i] = min(dp[i], dp[i - 3] + 1LL * (A[i - 1] + A[i]));
        }
    }
    cout << dp[N];
    return 0;
} 