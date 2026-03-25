#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3 + 5;

int N;
int A[mxN];

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
        if (A[i] < 0)
        {
            cout << A[i] << ' ';
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        if (A[i] > 0)
        {
            cout << A[i] << ' ';
        }
    }
    return 0;
}