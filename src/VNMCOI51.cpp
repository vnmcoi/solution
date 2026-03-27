#include <bits/stdc++.h>
using namespace std;

const int mxN = 100 + 5;

int N, M, X, Y;
int A[mxN][mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X >> Y;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> A[i][j];
        }
    }
    int ans = A[X][Y];
    for (int i = 1; X - i >= 1 && Y - i >= 1; ++i)
    {
        ans += A[X - i][Y - i];
    }
    for (int i = 1; X + i <= N && Y + i <= M; ++i)
    {
        ans += A[X + i][Y + i];
    }
    for (int i = 1; X - i >= 1 && Y + i <= M; ++i)
    {
        ans += A[X - i][Y + i];
    }
    for (int i = 1; X + i <= N && Y - i >= 1; ++i)
    {
        ans += A[X + i][Y - i];
    }
    cout << ans;
    return 0;
}