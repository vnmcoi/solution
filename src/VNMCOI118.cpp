#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;

int N;
int pos[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (pos[i - 1] > pos[i])
        {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}