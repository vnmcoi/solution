#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int ans = 0;
    for (int i = 5; i <= N; i *= 5)
    {
        ans += N / i;
    }
    cout << ans;
    return 0;
}