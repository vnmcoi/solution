#include <bits/stdc++.h>
using namespace std;

int N;
string S;

void wayslui(int pos)
{
    if (pos == N + 1)
    {
        cout << S << '\n';
        return;
    }
    for (char c = 'A'; c <= 'C'; ++c)
    {
        if (S.empty() == true || S.back() != c)
        {
            string temp = S;
            S += c;
            wayslui(pos + 1);
            S = temp;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    wayslui(1);
    return 0;
}