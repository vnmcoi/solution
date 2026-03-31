#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5;

int N;
int A[mxN];
long long S[mxN], T[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        S[i] = S[i - 1] + A[i];
    }
    for (int i = N; i >= 1; --i)
    {
        T[i] = T[i + 1] + A[i];
    }
    long long ans = -1e18;
    long long cnt = 0;
    long long maxS = -1e18;
    long long minS = 1e18;
    int cntMax = 0;
    int cntMin = 0;
    for (int i = 1; i <= N - 1; ++i)
    {
        if (S[i] > maxS)
        {
            maxS = S[i];
            cntMax = 1;
        }
        else if (S[i] == maxS)
        {
            ++cntMax;
        }
        if (S[i] < minS)
        {
            minS = S[i];
            cntMin = 1;
        }
        else if (S[i] == minS)
        {
            ++cntMin;
        }
        long long val1 = maxS - T[i + 1];
        if (val1 > ans)
        {
            ans = val1;
            cnt = cntMax;
        }
        else if (val1 == ans)
        {
            cnt += cntMax;
        }
        long long val2 = T[i + 1] - minS;
        if (val2 > ans)
        {
            ans = val2;
            cnt = cntMin;
        }
        else if (val2 == ans)
        {
            cnt += cntMin;
        }
    }
    if (ans == 0)
    {
        cnt /= 2;
    }
    cout << ans << ' ' << cnt;
    return 0;
}