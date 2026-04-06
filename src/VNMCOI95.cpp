#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

string S;
int pref[mxN];
int cnt[3];
int d = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("XOASO.INP", "r", stdin);
    freopen("XOASO.OUT", "w", stdout);
    cin >> S;
    int N = (int)S.length();
    S = ' ' + S;
    for (int i = 1; i <= N; ++i)
    {
        pref[i] = (pref[i - 1] + (S[i] - '0')) % 3;
    }
    d = pref[N];
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        ans += cnt[(((pref[i] - d) % 3) + 3) % 3];
        cnt[pref[i]]++;
    }
    --ans;
    if (d == 0)
    {
        ++ans;
    }
    cout << ans;
    return 0;
}s