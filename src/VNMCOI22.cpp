#include <bits/stdc++.h>
using namespace std;

int A, B, C, X, Y, Z;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C >> X >> Y >> Z;
    if (C < Z)
    {
        cout << 1;
    }
    else if (C > Z)
    {
        cout << 2;
    }
    else
    {
        if (B < Y)
        {
            cout << 1;
        }
        else if (B > Y)
        {
            cout << 2;
        }
        else
        {
            if (A < X)
            {
                cout << 1;
            }
            else if (A > X)
            {
                cout << 2;
            }
        }
    }
    return 0;
}