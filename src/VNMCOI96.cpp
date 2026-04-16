#include <bits/stdc++.h>
using namespace std;

int N;

void solve()
{
    cin >> N;
    cout << 1LL * N * (N + 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}