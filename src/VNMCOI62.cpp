#include <bits/stdc++.h>
using namespace std;

const int mxN = 2;

string S;
int cnt[mxN];

bool check(char c)
{
    return (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    long long ans = 0;
    for (int i = 0; i < (int)S.length(); ++i)
    {
        if (check(S[i]) == true)
        {
            ans += cnt[1];
            cnt[0]++;
        }
        else
        {
            ans += cnt[0];
            cnt[1]++;
        }
    }
    cout << ans;
    return 0;
}