#include <bits/stdc++.h>
using namespace std;

const int mxN = 20 + 5;

int N, K;
int A[mxN];

void wayslui(int pos, int cnt)
{
    if (cnt == K + 1)
    {
        for (int i = 1; i <= K; ++i)
        {
            cout << A[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (pos == N + 1)
    {
        return;
    }
    for (int i = pos; i <= N; ++i)
    {
        A[cnt] = i;
        wayslui(i + 1, cnt + 1);
        A[cnt] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    wayslui(1, 1);
    return 0;
}