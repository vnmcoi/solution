#include <bits/stdc++.h>
using namespace std;

long long N;

void solve()
{
    cin >> N;
    long long ans = 0;
    for (int i = 1; 1LL * i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            ans += i;
            if (N / i != i)
            {
                ans += N / i;
            }
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}