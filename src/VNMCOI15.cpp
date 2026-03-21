#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;

int N;
int A[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("BOIBA.INP", "r", stdin);
    freopen("BOIBA.OUT", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    long long ans = 0;
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        if ((cnt + A[i]) % 3 == 0)
        {
            continue;
        }
        else if ((cnt + A[i]) % 3 == 1)
        {
            ans += 2 * (N - i + 1);
            cnt += 2;
        }
        else
        {
            ans += 1 * (N - i + 1);
            cnt += 1;
        }
    }
    cout << ans;
    return 0;
}