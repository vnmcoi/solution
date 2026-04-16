#include <bits/stdc++.h>
using namespace std;

int l, r;

long long calc(int n)
{
    return 1LL * n * (n + 1) / 2;
}

void solve()
{
    cin >> l >> r;
    cout << calc(r) - calc(l - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}