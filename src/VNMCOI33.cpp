#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int cnt = 0;
    int cur = 0;
    while (N != 0)
    {
        ++cnt;
        ++cur;
        --N;
        if (cur == K)
        {
            ++N;
            cur = 0;
        }
    }
    cout << cnt;
    return 0;
}