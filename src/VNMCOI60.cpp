#include <bits/stdc++.h>
using namespace std;

string S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, S);
    int N = (int)S.length();
    for (int i = 0; i < N; ++i)
    {
        if (S[i] >= 'A' && S[i] <= 'Z')
        {
            cout << (char)(S[i] - 'A' + 'a');
        }
        else
        {
            cout << S[i];
        }
    }
    return 0;
}