#include <bits/stdc++.h>
using namespace std;

const int mxN = 500 + 5;

int N, M;
int A[mxN][mxN];
long long B[mxN];

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
    long long ans = -1e18;
    for (int top = 1; top <= N; ++top)
    {
        for (int j = 1; j <= M; ++j)
        {
            B[j] = 0;
        }
        for (int bottom = top; bottom <= N; ++bottom)
        {
            for (int j = 1; j <= M; ++j)
            {
                B[j] += A[bottom][j];
            }
            long long temp = B[1];
            long long best = B[1];
            for (int j = 2; j <= M; ++j)
            {
                temp = max(temp + B[j], B[j]);
                best = max(best, temp);
            }
            ans = max(ans, best);
        }
    }
    cout << ans;
    return 0;
}