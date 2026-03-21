#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, Q;
int A[mxN];
long long pref[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
        int L, R;
        cin >> L >> R;
        cout << pref[R] - pref[L - 1] << '\n';
    }
    return 0;
}