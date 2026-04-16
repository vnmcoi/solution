#include <bits/stdc++.h>
using namespace std;

const int mxN = 5 + 5;

int N;
int cnt[mxN];

void solve()
{
    cin >> N;
    int ans = 0, cur = 6;
    for (int i = 1; i <= N; ++i)
    {
        int A, B;
        cin >> A >> B;
        for (int j = 1; j <= 5; ++j)
        {
            if (j != A && j != B)
            {
                cnt[j] = 0;
            }
        }
        cnt[A]++;
        cnt[B]++;
        if (A == B)
        {
            cnt[B]--;
        }
        if (cnt[A] > ans)
        {
            ans = cnt[A];
            cur = A;
        }
        if (cnt[A] == ans && A < cur)
        {
            cur = A;
        }
        if (cnt[B] > ans)
        {
            ans = cnt[B];
            cur = B;
        }
        if (cnt[B] == ans && B < cur)
        {
            cur = B;
        }
    }
    cout << ans << ' ' << cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("CHONCAM.INP", "r", stdin);
    freopen("CHONCAM.OUT", "w", stdout);

    solve();
    return 0;
}