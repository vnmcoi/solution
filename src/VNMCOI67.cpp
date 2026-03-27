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
    string temp = S;
    S += '0';
    wayslui(pos + 1);
    S = temp;
    S += '1';
    wayslui(pos + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    wayslui(1);
    return 0;
}