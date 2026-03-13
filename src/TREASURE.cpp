#include <bits/stdc++.h>
using namespace std;

const int mxN = 500 + 5;

int R, C, M;
string S;
bitset<mxN> wall[mxN];
bitset<mxN> mask[mxN];
bitset<mxN> temp[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("TREASURE.INP", "r", stdin);
    freopen("TREASURE.OUT", "w", stdout);

    cin >> R >> C >> M;
    for (int i = 1; i <= R; ++i)
    {
        string T;
        cin >> T;
        for (int j = 0; j < C; ++j)
        {
            if (T[j] == '.')
            {
                wall[i][j] = 1;
                mask[i][j] = 1;
            }
        }
    }
    cin >> S;
    for (char c : S)
    {
        for (int i = 1; i <= R; ++i)
        {
            temp[i].reset();
        }
        if (c == 'D' || c == '?')
        {
            for (int i = 1; i <= R; ++i)
            {
                temp[i] |= (mask[i] << 1);
            }
        }
        if (c == 'T' || c == '?')
        {
            for (int i = 1; i <= R; ++i)
            {
                temp[i] |= (mask[i] >> 1);
            }
        }
        if (c == 'B' || c == '?')
        {
            for (int i = 1; i < R; ++i)
            {
                temp[i] |= mask[i + 1];
            }
        }
        if (c == 'N' || c == '?')
        {
            for (int i = 2; i <= R; ++i)
            {
                temp[i] |= mask[i - 1];
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
    return 0;
}