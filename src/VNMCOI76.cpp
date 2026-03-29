#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;

int N, M, Q;
long long pref[mxN][mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            int x;
            cin >> x;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + x;
        }
    }
    while (Q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1] << '\n';
    }
    return 0;
}