#include <bits/stdc++.h>
using namespace std;

const int mxN = 5;

int N;
int cnt[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("CHONDOI.INP", "r", stdin);
    freopen("CHONDOI.OUT", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        string S;
        cin >> S;
        if (S[0] == 'H')
        {
            cnt[0]++;
        }
        else if (S[0] == 'S')
        {
            cnt[1]++;
        }
        else if (S[0] == 'G')
        {
            cnt[2]++;
        }
        else if (S[0] == 'T')
        {
            cnt[3]++;
        }
        else if (S[0] == 'P')
        {
            cnt[4]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 5; ++j)
        {
            for (int z = j + 1; z < 5; ++z)
            {
                ans += 1LL * cnt[i] * cnt[j] * cnt[z];
            }
        }
    }
    cout << ans;
    return 0;
}