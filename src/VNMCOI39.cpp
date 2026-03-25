#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;

int N, Q;
int B[mxN];
int X[mxN];
int Y[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> B[i];
    }
    for (int i = 1; i <= Q; ++i)
    {
        cin >> X[i] >> Y[i];
    }
    for (int i = Q; i >= 1; --i)
    {
        swap(B[X[i]], B[Y[i]]);
    }
    for (int i = 1; i <= N; ++i)
    {
        cout << B[i] << ' ';
    }
    return 0;
}