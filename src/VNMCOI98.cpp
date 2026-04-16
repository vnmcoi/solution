#include <bits/stdc++.h>
using namespace std;

long long N;

long long calc(int n)
{
    return 1LL * n * (n + 1) / 2;
}

void solve()
{
    cin >> N;
    int ans = 0;
    for (int i = 2; calc(i) <= N; ++i)
    {
        if ((N * 2) % i == 0)
        {
            long long res = N * 2 / i;
            if ((i + res) % 2 == 1)
            {
                ++ans;
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