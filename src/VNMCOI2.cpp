#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5;

int N, Q;
int A[mxN];
long long pref[mxN];

void solve()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        pref[i] = pref[i - 1] + A[i];
    }
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}