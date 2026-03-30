#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5 + 5;

int N;
int A[mxN];
long long L[mxN], R[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    L[0] = R[N + 1] = -1e18;
    long long mn = 0;
    long long temp = 0;
    for (int i = 1; i <= N; ++i)
    {
        temp = temp + A[i];
        L[i] = max(L[i - 1], temp - mn);
        mn = min(mn, temp);
    }
    mn = 0;
    temp = 0;
    for (int i = N; i >= 1; --i)
    {
        temp = temp + A[i];
        R[i] = max(R[i + 1], temp - mn);
        mn = min(mn, temp);
    }
    long long ans = -1e18;
    for (int i = 1; i <= N; ++i)
    {
        ans = max(ans, L[i] + R[i + 1]);
    }
    cout << ans;
    return 0;
}