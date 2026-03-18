#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, Q;
long long pref[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        int X;
        cin >> X;
        pref[i] = pref[i - 1] + X;
    }
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
    return 0;
}