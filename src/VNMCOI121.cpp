#include <bits/stdc++.h>
using namespace std;

const int mxN = 10 + 5;

int N;
int A[mxN];
int B[mxN];
int p[mxN];
bitset<mxN> used;

long long ans = 0x3f3f3f3f3f3f3f3f;

void wayslui(int pos)
{
    if (pos == N + 1)
    {
        long long time1 = 0, time2 = 0;
        for (int i = 1; i <= N; i++)
        {
            int idx = p[i];
            time1 += A[idx];
            time2 = max(time2, time1) + B[idx];
        }
        ans = min(ans, time2);
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (used[i] == false)
        {
            used[i] = true;
            p[pos] = i;
            wayslui(pos + 1);
            used[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }
    wayslui(1);
    cout << ans;
    return 0;
}