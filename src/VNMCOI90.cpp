#include <bits/stdc++.h>
using namespace std;

int N;
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("BWPOINTS.INP", "r", stdin);
    freopen("BWPOINTS.OUT", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        mp[x] = -1;
    }
    int ans = 0;
    int last = 0;
    for (map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
    {
        if (last == 0)
        {
            last = itr->second;
        }
        else if (last + itr->second == 0)
        {
            ++ans;
            last = 0;
        }
        else
        {
            last = itr->second;
        }
    }
    cout << ans;
    return 0;
}
