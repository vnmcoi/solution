#include <bits/stdc++.h>
using namespace std;

const int mxN = 50 + 5;

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
    for (int s = 2; s <= N + M; ++s)
    {
        if (s % 2 == 1)
        {
            for (int i = max(1, s - M); i <= min(N, s - 1); ++i)
            {
                cout << A[i][s - i] << ' ';
            }
        }
        else
        {
            for (int i = min(N, s - 1); i >= max(1, s - M); --i)
            {
                cout << A[i][s - i] << ' ';
            }
        }
    }
    return 0;
}