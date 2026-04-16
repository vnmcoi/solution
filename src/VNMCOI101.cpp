#include <bits/stdc++.h>
using namespace std;

const int mxN = 10;

string N;
int cnt[mxN];

void solve()
{
    cin >> N;
    for (int i = 0; i < (int)N.length(); ++i)
    {
        cnt[N[i] - '0']++;
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (cnt[i] != 0)
        {
            cout << i;
            cnt[i]--;
            break;
        }
    }
    for (int i = 0; i <= 9; ++i)
    {
        if (cnt[i] != 0)
        {
            for (int j = 1; j <= cnt[i]; ++j)
            {
                cout << i;
            }
            cnt[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}