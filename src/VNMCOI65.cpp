#include <bits/stdc++.h>
using namespace std;

string S, T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> T;
    int N = (int)S.length();
    int M = (int)T.length();
    int cnt = 1;
    for (int i = 1; i < N; ++i)
    {
        if (S[i] != S[i - 1])
        {
            cout << cnt << S[i - 1];
            cnt = 1;
        }
        else
        {
            ++cnt;
        }
    }
    cout << cnt << S[N - 1];
    cout << '\n';
    cnt = 0;
    for (int i = 0; i < M; ++i)
    {
        if (T[i] >= '0' && T[i] <= '9')
        {
            cnt = cnt * 10 + (T[i] - '0');
        }
        else
        {
            for (int j = 1; j <= cnt; ++j)
            {
                cout << T[i];
            }
            cnt = 0;
        }
    }
    return 0;
}