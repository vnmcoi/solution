#include <bits/stdc++.h>
using namespace std;

string S;

bool check(string s)
{
    string t = "";
    for (int i = (int)s.length() - 1; i >= 0; --i)
    {
        t += s[i];
    }
    return t == s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    int N = (int)S.length();
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        string T = "";
        for (int j = i; j < N; ++j)
        {
            T += S[j];
            if (check(T) == true)
            {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}