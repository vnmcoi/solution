#include <bits/stdc++.h>
using namespace std;

int N;
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("BANGNHAU.INP", "r", stdin);
    freopen("BANGNHAU.OUT", "w", stdout);

    cin >> N;
    int k = 0, x = 0;
    for (int i = 1; i <= N; ++i)
    {
        int X;
        cin >> X;
        mp[X]++;
        if (mp[X] > k)
        {
            k = mp[X];
            x = X;
        }
        if (mp[X] == k && X < x)
        {
            x = X;
        }
    }
    cout << k << ' ' << x;
    return 0;
}