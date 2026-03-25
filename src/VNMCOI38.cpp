#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;

int N;
int A[mxN * 2];
int X, Y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        A[i + N] = A[i];
    }
    cin >> X >> Y;
    if (X > Y)
    {
        swap(X, Y);
    }
    int ans1 = 0, ans2 = 0;
    for (int i = X; i < Y; ++i)
    {
        ans1 += A[i];
    }
    for (int i = Y; i < X + N; ++i)
    {
        ans2 += A[i];
    }
    cout << min(ans1, ans2);
    return 0;
}