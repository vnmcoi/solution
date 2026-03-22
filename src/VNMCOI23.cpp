#include <bits/stdc++.h>
using namespace std;

int A, B, C, D;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C >> D;
    if (A == C || A == D || B == C || B == D)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}