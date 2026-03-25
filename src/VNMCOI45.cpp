#include <bits/stdc++.h>
using namespace std;

int a, b;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("HOCTOAN.INP", "r", stdin);
    freopen("HOCTOAN.OUT", "w", stdout);

    cin >> a >> b;

    if (b % a != 0)
    {
        cout << -1;
        return 0;
    }

    int k = b / a;
    int best_u = -1, best_v = -1;
    int best_sum = 1e9;

    for (int u = 1; u * u <= k; ++u)
    {
        if (k % u != 0)
        {
            continue;
        }
        int v = k / u;
        if (gcd(u, v) != 1)
        {
            continue;
        }
        if (u + v < best_sum)
        {
            best_sum = u + v;
            best_u = u;
            best_v = v;
        }
    }
    if (best_u == -1)
    {
        cout << -1;
        return 0;
    }
    int x = a * best_u;
    int y = a * best_v;
    cout << x + y << '\n';
    cout << x << ' ' << y;
    return 0;
}