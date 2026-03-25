#include <bits/stdc++.h>
using namespace std;

int N;

long long Pow(int n)
{
    long long res = 1;
    for (int i = 1; i <= 5; ++i)
    {
        res *= 1LL * n;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N)
    {
        if (N == 0)
        {
            break;
        }
        else
        {
            cout << Pow(N) << '\n';
        }
    }
    return 0;
}