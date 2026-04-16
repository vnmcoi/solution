#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e5 + 5;

int N;
pair<int, int> A[mxN];

struct compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;
    }
};

void solve()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i].first >> A[i].second;
    }
    sort(A + 1, A + 1 + N, compare());
    int ans = 0;
    int res = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (A[i].first > res)
        {
            ++ans;
            res = A[i].second;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}