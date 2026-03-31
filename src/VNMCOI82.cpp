#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

const int mxN = 1e3 + 5;

int N, K;
int A[mxN][mxN];
int B[mxN + mxN][mxN + mxN];
long long pref[mxN + mxN][mxN + mxN];

long long calc(int x1, int y1, int x2, int y2)
{
    if (x1 > x2 || y1 > y2)
    {
        return 0;
    }
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> A[i][j];
            int x = i + j;
            int y = i - j + N;
            B[x][y] = A[i][j];
        }
    }
    FOR(i, 1, N + N)
    {
        FOR(j, 1, N + N)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + B[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int x = i + j;
            int y = i - j + N;
            int x1 = max(1, x - K);
            int y1 = max(1, y - K);
            int x2 = min(N + N, x + K);
            int y2 = min(N + N, y + K);
            ans = max(ans, calc(x1, y1, x2, y2));
        }
    }
    cout << ans;
    return 0;
}