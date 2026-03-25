#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long ans = 1;
    for (int i = 1; i <= N; ++i)
    {
        ans *= i;
    }
    cout << ans;
    return 0;
}