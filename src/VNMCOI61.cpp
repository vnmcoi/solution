#include <bits/stdc++.h>
using namespace std;

string S;

bool check(char c)
{
    return (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i' || c == 'U' || c == 'E' || c == 'O' || c == 'A' || c == 'I');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, S);
    int N = (int)S.length();
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (check(S[i]) == true)
        {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}