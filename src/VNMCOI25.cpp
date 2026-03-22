#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    if (A < B + C && B < A + C && C < A + B)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}