#include <bits/stdc++.h>
using namespace std;

int A, B;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    if (A == 0)
    {
        if (B == 0)
        {
            cout << "INFINITE SOLUTIONS";
        }
        else
        {
            cout << "NO SOLUTION";
        }
    }
    else if (abs(B) % abs(A) != 0)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        cout << -B / A;
    }
    return 0;
}