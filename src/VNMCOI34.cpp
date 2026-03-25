#include <bits/stdc++.h>
using namespace std;

int A, B, K;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> K;
    A %= B;
    for (int i = 1; i < K; ++i)
    {
        A *= 10;
        A %= B;
    }
    cout << A * 10 / B;
    return 0;
}