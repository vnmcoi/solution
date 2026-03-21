#include <bits/stdc++.h>
using namespace std;

const int mxN = 400 + 5;
const int mxK = 400 + 5;
const int INF = 0x3f3f3f3f;

int N, K;
int D[mxN];
int f[mxN][mxK];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("BANTAU.INP", "r", stdin);
    freopen("BANTAU.OUT", "w", stdout);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> D[i];
    }
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int k = 1; k <= K + 1; ++k)
        {
            int mx = 0;
            int sum = 0;
            for (int j = i; j >= 1; --j)
            {
                mx = max(mx, D[j]);
                sum += D[j];
                int cost = (i - j + 1) * mx - sum;
                f[i][k] = min(f[i][k], f[j - 1][k - 1] + cost);
            }
        }
    }
    cout << f[N][K + 1];
    return 0;
}