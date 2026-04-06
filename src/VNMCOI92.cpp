#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5 + 5;

int N;
int A[mxN];
int cnt = 0;

bool check(int x)
{
    if (x == 1)
    {
        return false;
    }
    int res = 1;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            int j = x / i;
            res += i;
            if (j != i)
            {
                res += j;
            }
        }
    }
    return res == x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("QUA.INP", "r", stdin);
    freopen("QUA.OUT", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        if (check(x) == true)
        {
            A[++cnt] = x;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; ++i)
    {
        cout << A[i] << ' ';
    }
    return 0;
}