#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;

int N;
int K[mxN];
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> K[i];
    }
    int j = 1;
    int ans = 0;
    mp[K[1]]++;
    for (int i = 1; i <= N; ++i)
    {
        while (j + 1 <= N && mp[K[j + 1]] == 0)
        {
            mp[K[++j]]++;
        }
        mp[K[i]]--;
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return 0;
}