#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5;

int N, q;
int A[mxN];
long long f[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("LEHOI.INP", "r", stdin);
    freopen("LEHOI.OUT", "w", stdout);

    cin >> N >> q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + N);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (i - 1 >= 0)
        {
            f[i] = min(f[i], f[i - 1] + 1LL * A[i] * (100 - q) / 100);
        }
        if (i - 2 >= 0)
        {
            f[i] = min(f[i], f[i - 2] + 1LL * (A[i - 1] + A[i]) * (100 - q) / 100);
        }
        if (i - 3 >= 0)
        {
            f[i] = min(f[i], f[i - 3] + 1LL * (A[i - 1] + A[i]));
        }
    }
    cout << f[N];
    return 0;
}