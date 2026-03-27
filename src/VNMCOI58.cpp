#include <bits/stdc++.h>
using namespace std;

string S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, S);
    int N = (int)S.length();
    bool ok = false;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] == ' ' && ok == true)
        {
            ++cnt;
            ok = false;
        }
        if (S[i] != ' ')
        {
            ok = true;
        }
    }
    cout << cnt + ok;
    return 0;
}