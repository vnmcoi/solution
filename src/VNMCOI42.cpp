#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;

int N;
int cnt[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    long long ans = 0;
    for (int i = 1; i <= 1e3; ++i)
    {
        for (int j = 1; j <= 1e3; ++j)
        {
            ans += 1LL * cnt[i] * cnt[j] * (i % j);
        }
    }
    cout << ans;
    return 0;
}