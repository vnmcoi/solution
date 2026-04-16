#include <bits/stdc++.h>
using namespace std;

const int mxN = 2025 + 5;

int N, M;
int A[mxN][mxN];
int f[mxN][mxN][3];

void solve()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> A[i][j];
        }
    }
    memset(f, -0x3f, sizeof(f));
    f[1][1][0] = A[1][1];
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            if (j - 1 >= 1)
            {
                for (int k = 0; k <= 2; ++k)
                {
                    f[i][j][0] = max(f[i][j][0], f[i][j - 1][k] + A[i][j]);
                }
            }
            if (i - 1 >= 1)
            {
                for (int k = 1; k <= 2; ++k)
                {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + A[i][j]);
                }
            }
        }
    }
    cout << max(f[N][M][0], max(f[N][M][1], f[N][M][2]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("MATRIX3.INP", "r", stdin);
    freopen("MATRIX3.OUT", "w", stdout);

    solve();
    return 0;
}