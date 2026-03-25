#include <bits/stdc++.h>
using namespace std;

int N, M;
string S, T;
map<int, map<int, int>> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);

    cin >> M >> N >> S >> T;
    int x = 1;
    int y = 1;
    for (int i = 0; i < (int)S.length(); ++i)
    {
        mp[x][y] = true;
        if (S[i] == 'D')
        {
            ++x;
        }
        else
        {
            ++y;
        }
    }
    int ans = 2;
    x = M;
    y = N;
    for (int i = 0; i < (int)T.length(); ++i)
    {
        ans += mp[x][y];
        if (T[i] == 'U')
        {
            --x;
        }
        else
        {
            --y;
        }
    }
    cout << ans;
    return 0;
}