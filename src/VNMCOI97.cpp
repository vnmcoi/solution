#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e4 + 5;
const int mxQ = 1e5 + 5;

int N, Q;
int A[mxN];
pair<int, int> querry[mxQ];
int mxA = 0;

void init(void)
{
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        mxA = max(mxA, A[i]);
    }
    for (int i = 1; i <= Q; ++i)
    {
        cin >> querry[i].first >> querry[i].second;
    }
}

namespace subtask1
{
    bool check(void)
    {
        return N <= 100 && Q <= 100 && mxA <= 1e5;
    }

    void solve(void)
    {
        for (int q = 1; q <= Q; ++q)
        {
            int ans = 0;
            for (int i = querry[q].first; i <= querry[q].second; ++i)
            {
                for (int j = querry[q].first; j <= querry[q].second; ++j)
                {
                    ans += (A[i] % A[j]);
                }
            }
            cout << ans << '\n';
        }
    }
};

namespace subtask2
{
    int pref[mxN][11];

    bool check(void)
    {
        return N <= 5e4 && Q <= 1e5 && mxA <= 10;
    }

    void solve(void)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= 10; ++j)
            {
                pref[i][j] = pref[i - 1][j] + (A[i] == j);
            }
        }
        for (int q = 1; q <= Q; ++q)
        {
            long long ans = 0;
            for (int i = 1; i <= 10; ++i)
            {
                for (int j = 1; j <= 10; ++j)
                {
                    ans += 1LL * (pref[querry[q].second][i] - pref[querry[q].first - 1][i]) * (pref[querry[q].second][j] - pref[querry[q].first - 1][j]) * (i % j);
                }
            }
            cout << ans << '\n';
        }
    }
};

namespace subtask3
{
    const int mxn = 1e3 + 1;

    long long pref[mxn][mxn];

    bool check(void)
    {
        return N <= 1e3 && Q <= 1e5 && mxA <= 1e5;
    }

    void solve(void)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (A[i] % A[j]);
            }
        }
        for (int q = 1; q <= Q; ++q)
        {
            cout << pref[querry[q].second][querry[q].second] - pref[querry[q].first - 1][querry[q].second] - pref[querry[q].second][querry[q].first - 1] + pref[querry[q].first - 1][querry[q].first - 1] << '\n';
        }
    }
};

namespace subtask4
{
    const int mxn = 1e4 + 5;
    const int mxa = 1e3 + 5;

    int cnt[mxa][mxn];
    int pref[mxa][mxn];

    bool check(void)
    {
        return N <= 1e4 && Q <= 1e4 && mxA <= 1e3;
    }

    void solve(void)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= 1e3; ++j)
            {
                cnt[j][i] = cnt[j][i - 1] + (A[i] == j);
            }
        }
        for (int j = 1; j <= 1e3; ++j)
        {
            for (int i = 1; i <= N; ++i)
            {
                pref[j][i] = pref[j][i - 1] + (A[i] % j);
            }
        }
        for (int q = 1; q <= Q; ++q)
        {
            long long ans = 0;
            for (int j = 1; j <= 1e3; ++j)
            {
                ans += 1LL * (pref[j][querry[q].second] - pref[j][querry[q].first - 1]) * (cnt[j][querry[q].second] - cnt[j][querry[q].first - 1]);
            }
            cout << ans << '\n';
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("THAOTAC.INP", "r", stdin);
    freopen("THAOTAC.OUT", "w", stdout);
    init();
    if (subtask1::check() == true)
    {
        return subtask1::solve(), 0;
    }
    if (subtask2::check() == true)
    {
        return subtask2::solve(), 0;
    }
    if (subtask3::check() == true)
    {
        return subtask3::solve(), 0;
    }
    if (subtask4::check() == true)
    {
        return subtask4::solve(), 0;
    }
    return 0;
}