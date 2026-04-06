#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, K;
int A[mxN];
long long pref[mxN];

int bs(int x)
{
    int l = 0;
    int r = N + 1;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (pref[mid] - pref[x - 1] < K)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        pref[i] = pref[i - 1] + A[i];
    }
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int pos = bs(i);
        ans += N - pos + 1;
    }
    cout << ans;
    return 0;
}