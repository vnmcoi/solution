#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;

int N, Q;
int A[mxN];
long long B[mxN];
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
    while (Q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        B[l] += x;
        B[r + 1] -= x;
    }
    for (int i = 1; i <= N; ++i)
    {
        pref[i] = pref[i - 1] + B[i];
        cout << A[i] + pref[i] << ' ';
    }
    return 0;
}