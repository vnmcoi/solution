#include <bits/stdc++.h>
using namespace std;

int N, A, B;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("NANGLUONG.INP", "r", stdin);
    freopen("NANGLUONG.OUT", "w", stdout);

    cin >> N >> A >> B;
    if (A * N % (A + B) != 0)
    {
        cout << -1;
    }
    else
    {
        int y = A * N / (A + B);
        cout << y;
    }
    return 0;
}