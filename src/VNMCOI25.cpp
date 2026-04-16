#include <bits/stdc++.h>
using namespace std;

int A, B, C;

void solve()
{
    cin >> A >> B >> C;
    if (A < B + C && B < A + C && C < A + B)
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