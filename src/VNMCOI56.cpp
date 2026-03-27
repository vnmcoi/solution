#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2 + 5;

int N, M;
int A[mxN][mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> A[i][j];
        }
    }
    for (int j = 1; j <= M; ++j)
    {
        int ans = 0;
        for (int i = 1; i <= N; ++i)
        {
            ans += A[i][j];
        }
        cout << ans << ' ';
    }
    return 0;
}