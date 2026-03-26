#include <bits/stdc++.h>
using namespace std;

const int mxN = 50 + 5;

int N;
long long C[mxN][mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    C[0][0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}