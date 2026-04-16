#include <bits/stdc++.h>
using namespace std;

int N, A, B;

void solve()
{
    cin >> N >> A >> B;
    if (A * N % (A + B) != 0)
    {
        cout << -1;
    }
    else
    {
        int y = A * N / (A + B);
        cout << y;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("NANGLUONG.INP", "r", stdin);
    freopen("NANGLUONG.OUT", "w", stdout);

    solve();
    return 0;
}