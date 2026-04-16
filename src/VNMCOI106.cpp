#include <bits/stdc++.h>
using namespace std;

int N;

int calc(int x)
{
    int cnt = 0;
    while (x != 0)
    {
        x /= 10;
        ++cnt;
    }
    return cnt;
}

void solve()
{
    cin >> N;
    int temp = 3;
    int cnt = 0;
    while (cnt + calc(temp + 1) <= N)
    {
        ++temp;
        cnt += calc(temp);
    }
    cout << temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("SOTRANG.INP", "r", stdin);
    freopen("SOTRANG.OUT", "w", stdout);

    solve();
    return 0;
}