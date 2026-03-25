#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N;
int cnt[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        ans += cnt[x];
        cnt[x]++;
    }
    cout << ans;
    return 0;
}