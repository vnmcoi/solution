#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;

int N, M, Q;
int A[mxN][mxN];
long long pref[mxN][mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> Q;
    while (Q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A[a][b]++;
        A[a][d + 1]--;
        A[c + 1][b]--;
        A[c + 1][d + 1]++;
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + A[i][j];
            cout << pref[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}