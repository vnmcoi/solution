#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;

int N;
int A[mxN];

void solve()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    long long ans = 0;
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        if ((cnt + A[i]) % 3 == 0)
        {
            continue;
        }
        else if ((cnt + A[i]) % 3 == 1)
        {
            ans += 2 * (N - i + 1);
            cnt += 2;
        }
        else
        {
            ans += 1 * (N - i + 1);
            cnt += 1;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("BOIBA.INP", "r", stdin);
    freopen("BOIBA.OUT", "w", stdout);

    solve();
    return 0;
}