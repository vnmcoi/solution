#include <bits/stdc++.h>
using namespace std;

const int mxN = 100 + 5;

int N;
int A[mxN][mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x <= x2; ++x)
        {
            for (int y = y1; y <= y2; ++y)
            {
                A[x][y]++;
            }
        }
    }
    int ans = 0;
    for (int x = 1; x < mxN; ++x)
    {
        for (int y = 1; y < mxN; ++y)
        {
            ans += (A[x][y] > 0);
        }
    }
    cout << ans;
    return 0;
}