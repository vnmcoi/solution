#include <iostream>
#include <cstdio>

using namespace std;

void solve()
{
    long long K;
    cin >> K;

    if (K == 1)
    {
        cout << 1 << " " << 1 << "\n";
        return;
    }

    if (K % 3 == 0)
    {
        cout << -1 << "\n";
        return;
    }

    long long m = 1;
    for (; m <= 8; ++m)
    {
        if ((m * (K % 9)) % 9 == 8)
        {
            break;
        }
    }

    long long first_digit;
    if (K <= 8)
    {
        first_digit = K - 1;
    }
    else
    {
        first_digit = K % 9;
    }

    long long sum_of_digits = (m + 1) * K;

    cout << first_digit << " " << sum_of_digits << "\n";
}

int main()
{
    if (fopen("SODEP.INP", "r"))
    {
        freopen("SODEP.INP", "r", stdin);
        freopen("SODEP.OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (cin >> Q)
    {
        while (Q--)
        {
            solve();
        }
    }

    return 0;
}