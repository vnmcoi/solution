#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;

int N, K;
int A[mxN];

void solve()
{
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + N);
    int i = 1;
    int j = N;
    int ans = 0;
    while (i <= j)
    {
        if (A[i] + A[j] <= K)
        {
            ++ans;
            ++i;
            --j;
        }
        else if (A[i] + A[j] > K)
        {
            ++ans;
            --j;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}