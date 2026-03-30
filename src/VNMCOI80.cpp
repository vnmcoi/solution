#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, D;
long long pref[mxN];
unordered_map<int, int> cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D;
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
        ans += cnt[((pref[i] % D) + D) % D];
        cnt[((pref[i] % D) + D) % D]++;
    }
    cout << ans;
    return 0;
}
