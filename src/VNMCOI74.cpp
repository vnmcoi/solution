#include <bits/stdc++.h>
using namespace std;

const int mxN = 100 + 5;

int N;
int A[mxN][mxN];
bitset<mxN * mxN> vis;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            vis.reset();
            for (int x = i - 1; x >= 1; --x)
            {
                vis[A[x][j]] = true;
            }
            for (int y = j - 1; y >= 1; --y)
            {
                vis[A[i][y]] = true;
            }
            int mn = 0;
            while (true)
            {
                if (vis[mn] == false)
                {
                    A[i][j] = mn;
                    break;
                }
                ++mn;
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}