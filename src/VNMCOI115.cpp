#include <bits/stdc++.h>
using namespace std;

int N;
int cnt[5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("AODAI.INP", "r", stdin);
    freopen("AODAI.OUT", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int S;
        cin >> S;
        cnt[S]++;
    }
    int ans = cnt[4];
    if (cnt[3] != 0 && cnt[1] != 0)
    {
        int mn = min(cnt[3], cnt[1]);
        ans += mn;
        cnt[3] -= mn;
        cnt[1] -= mn;
        if (cnt[3] != 0)
        {
            ans += cnt[3];
        }
    }
    else if (cnt[3] != 0 && cnt[1] == 0)
    {
        ans += cnt[3];
    }
    int rem_2 = cnt[2] % 2;
    ans += cnt[2] / 2;
    if (rem_2 == 0)
    {
        ans += cnt[1] / 4;
        if (cnt[1] % 4 != 0)
        {
            ans += 1;
        }
    }
    else
    {
        if (cnt[1] <= 2)
        {
            ans += 1;
        }
        else
        {
            ans += 1;
            cnt[1] -= 2;
            ans += cnt[1] / 4;
            if (cnt[1] % 4 != 0)
            {
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}