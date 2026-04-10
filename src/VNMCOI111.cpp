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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("SOTRANG.INP", "r", stdin);
    freopen("SOTRANG.OUT", "w", stdout);
    cin >> N;
    int temp = 3;
    int cnt = 0;
    while (cnt + calc(temp + 1) <= N)
    {
        ++temp;
        cnt += calc(temp);
    }
    cout << temp;
    return 0;
}