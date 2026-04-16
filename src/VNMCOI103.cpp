#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;

int N;
int A[mxN][mxN];
long long pref[mxN][mxN];

void solve()
{
    cin >> N;
    int mn = 1e9;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> A[i][j];
            mn = min(mn, A[i][j]);
            pref[i][j] = pref[i][j - 1] + A[i][j];
        }
    }
    if (mn < 0)
    {
        cout << "NO";
        return;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (A[i][i] < pref[i][N] - A[i][i])
        {
            cout << "NO";
            return;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (A[i][i] > pref[i][N] - A[i][i])
        {
            ++ans;
        }
    }
    if (ans != 0)
    {
        cout << "YES\n"
             << ans;
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TROICHEO.INP", "r", stdin);
    freopen("TROICHEO.OUT", "w", stdout);

    solve();
    return 0;
}