#include <bits/stdc++.h>
using namespace std;

int A, B;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    int mn = min(A, B);
    while (mn > 0)
    {
        if (A % mn == 0 && B % mn == 0)
        {
            break;
        }
        --mn;
    }
    cout << A / mn << ' ' << B / mn;
    return 0;
}