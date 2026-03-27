#include <bits/stdc++.h>
using namespace std;

string S;
int k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, S);
    cin >> k;
    int N = (int)S.length();
    for (int i = 0; i < N; ++i)
    {
        if (S[i] != ' ')
        {
            cout << (char)((S[i] - 'a' + k) % 26 + 'a');
        }
        else
        {
            cout << ' ';
        }
    }
    return 0;
}