#include <bits/stdc++.h>
using namespace std;

int A, B, C, D;

void solve()
{
    cin >> A >> B >> C >> D;
    if (A == C || A == D || B == C || B == D)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}