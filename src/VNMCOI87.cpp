#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, Q;
int A[mxN];

int bs(int x)
{
    int l = 0;
    int r = N + 1;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (A[mid] <= x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    while (Q--)
    {
        int x;
        cin >> x;
        cout << bs(x) << '\n';
    }
    return 0;
}