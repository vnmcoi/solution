#include <bits/stdc++.h>
using namespace std;

const int mxN = 50 + 5;

int N;
int A[mxN][mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> A[i][j];
        }
    }
    for (int j = 1; j <= N; ++j)
    {
        for (int i = N; i >= 1; --i)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}