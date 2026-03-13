#include <bits/stdc++.h>
using namespace std;

const int mxN = 25e3 + 5;

int A, B, N, M;
int a[mxN];
int b[mxN];
int va[mxN];
int hb[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("RUTVAN.INP", "r", stdin);
    freopen("RUTVAN.OUT", "w", stdout);

    cin >> A >> B >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= M; ++j)
    {
        cin >> b[j];
    }
    sort(a + 1, a + 1 + N);
    va[1] = a[1];
    for (int i = 2; i <= N; ++i)
    {
        va[i] = a[i] - a[i - 1];
    }
    va[N + 1] = A - a[N];
    sort(b + 1, b + 1 + M);
    hb[1] = b[1];
    for (int i = 2; i <= M; ++i)
    {
        hb[i] = b[i] - b[i - 1];
    }
    hb[M + 1] = B - b[M];
    ++N;
    ++M;
    sort(va + 1, va + 1 + N);
    sort(hb + 1, hb + 1 + M);
    long long ans = 1LL * va[1] * (M - 1) + 1LL * hb[1] * (N - 1);
    int vi = 1, hi = 1;
    while (vi < N && hi < M)
    {
        if (va[vi + 1] < hb[hi + 1])
        {
            ++vi;
            ans += 1LL * va[vi] * (M - hi);
        }
        else
        {
            ++hi;
            ans += 1LL * hb[hi] * (N - vi);
        }
    }
    cout << ans;
    return 0;
}