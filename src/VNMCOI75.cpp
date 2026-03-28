#include <bits/stdc++.h>
using namespace std;

const int mxN = 9 + 5;

int N;
int A[mxN];
bitset<mxN> vis;

void wayslui(int pos)
{
    if (pos == N + 1)
    {
        for (int i = 1; i <= N; ++i)
        {
            cout << A[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (vis[i] == false)
        {
            A[pos] = i;
            vis[i] = true;
            wayslui(pos + 1);
            A[pos] = 0;
            vis[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    wayslui(1);
    return 0;
}