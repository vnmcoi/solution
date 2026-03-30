#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, K;
long long pref[mxN];
unordered_map<long long, int> cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
        long long val = pref[i] - 1LL * K * i;
        ans += cnt[val];
        cnt[val]++;
    }
    cout << ans;
    return 0;
}