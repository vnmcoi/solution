#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
const int OFFSET = 1e5;

int N;
int cnt[mxN + OFFSET];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        cnt[x + OFFSET]++;
        if (cnt[x + OFFSET] == 3)
        {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}