#include <bits/stdc++.h>
using namespace std;

const int mxN = 10 + 5;

int N, K;
int groups[mxN];
int groups_sum[mxN];
int A[mxN];
int sum = 0;
bool ok = false;

void wayslui(int pos)
{
    if (ok == true)
    {
        return;
    }
    if (pos == N + 1)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (groups[i] == 0)
            {
                return;
            }
        }
        ok = true;
        for (int i = 1; i <= N; ++i)
        {
            cout << groups[i] << ' ';
        }
        return;
    }
    for (int i = 1; i <= K; ++i)
    {
        if (groups_sum[i] + A[pos] <= sum / K)
        {
            groups_sum[i] += A[pos];
            groups[pos] = i;
            wayslui(pos + 1);
            groups_sum[i] -= A[pos];
            groups[pos] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        sum += A[i];
    }
    if (sum % K != 0)
    {
        cout << "-1";
        return 0;
    }
    wayslui(1);
    if (ok == false)
    {
        cout << "-1";
    }
    return 0;
}