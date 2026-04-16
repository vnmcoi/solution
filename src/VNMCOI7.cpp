#include <bits/stdc++.h>
using namespace std;

const int mxN = 500 + 5;

int R, C, M;
bitset<mxN> mask[mxN];
bitset<mxN> wall[mxN];
bitset<mxN> temp[mxN];
string S;

void solve()
{
    cin >> R >> C >> M;
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            char c;
            cin >> c;
            if (c == '.')
            {
                wall[i][j] = 1;
                mask[i][j] = 1;
            }
        }
    }
    cin >> S;
    for (int m = 0; m < M; ++m)
    {
        for (int i = 1; i <= R; ++i)
        {
            temp[i].reset();
        }
        if (S[m] == 'D' || S[m] == '?')
        {
            for (int i = 1; i <= R; ++i)
            {
                temp[i] |= (mask[i] << 1);
            }
        }
        if (S[m] == 'T' || S[m] == '?')
        {
            for (int i = 1; i <= R; ++i)
            {
                temp[i] |= (mask[i] >> 1);
            }
        }
        if (S[m] == 'N' || S[m] == '?')
        {
            for (int i = 1; i <= R; ++i)
            {
                temp[i] |= mask[i - 1];
            }
        }
        if (S[m] == 'B' || S[m] == '?')
        {
            for (int i = 1; i <= R; ++i)
            {
                temp[i] |= mask[i + 1];
            }
        }
        for (int i = 1; i <= R; ++i)
        {
            mask[i] = temp[i] & wall[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= R; ++i)
    {
        ans += mask[i].count();
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("TREASURE.INP", "r", stdin);
    freopen("TREASURE.OUT", "w", stdout);

    solve();
    return 0;
}