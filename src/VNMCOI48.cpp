#include <bits/stdc++.h>
using namespace std;

const int mxN = 500 + 5;

int N, K;
int A[mxN * mxN];

int bs(int x)
{
    int lo = 0;
    int hi = N * N + 1;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) >> 1;
        if (A[x] + A[mid] <= K)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("KHUYENMAI.INP", "r", stdin);
    freopen("KHUYENMAI.OUT", "w", stdout);

    cin >> N >> K;
    for (int i = 1; i <= N * N; ++i)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + N * N);
    int ans = 0;
    for (int i = 1; i <= N * N; ++i)
    {
        int pos = bs(i);
        if (pos <= i)
        {
            continue;
        }
        ans = max(ans, A[i] + A[pos]);
    }
    cout << ans;
    return 0;
}