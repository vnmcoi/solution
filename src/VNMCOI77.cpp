#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N;
long long pref[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long ans = -1e18;
    long long mn = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
        ans = max(ans, pref[i] - mn);
        mn = min(mn, pref[i]);
    }
    cout << ans;
    return 0;
}