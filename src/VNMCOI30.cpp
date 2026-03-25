#include <bits/stdc++.h>
using namespace std;

long long N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long temp = 1;
    int cnt = 0;
    while (temp < N)
    {
        temp *= 2;
        ++cnt;
    }
    cout << cnt;
    return 0;
}