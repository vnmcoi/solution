#include <bits/stdc++.h>
using namespace std;

string S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, S);
    int N = (int)S.length();
    long long ans = 0;
    long long temp = 0;
    bool ok = false;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            temp = temp * 10 + (S[i] - '0');
            ok = true;
        }
        else if (S[i] == ' ' && ok == true)
        {
            ans += temp;
            temp = 0;
            ok = false;
        }
        else
        {
            ok = true;
        }
    }
    cout << ans + temp;
    return 0;
}