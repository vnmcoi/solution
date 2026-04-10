#include <bits/stdc++.h>
using namespace std;

long long K;

bool check(long long x)
{
    return ((x / 3) + (x / 5) + (x / 7) - (x / 15) - (x / 21) - (x / 35) + (x / 105)) >= K;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    long long l = 0;
    long long r = 1e18 + 1;
    while (r - l > 1)
    {
        long long mid = (l + r) >> 1;
        if (check(mid) == true)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r;
    return 0;
}