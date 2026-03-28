#include <bits/stdc++.h>
using namespace std;

const int mxN = 20 + 5;

int N;
long long K;
long long A[mxN];
bool ok = false;

void wayslui(int pos, long long sum)
{
    if (sum > K)
    {
        return;
    }
    if (sum == K)
    {
        ok = true;
        return;
    }
    if (pos == N + 1)
    {
        return;
    }
    if (ok == true)
    {
        return;
    }
    wayslui(pos + 1, sum + A[pos]);
    wayslui(pos + 1, sum);
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
    wayslui(1, 0);
    if (ok == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}