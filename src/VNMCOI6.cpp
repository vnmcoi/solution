#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> st;

void solve()
{
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        while (st.empty() == false && st.top() > a)
        {
            st.pop();
        }
        if (st.empty() == false && st.top() == a)
        {
            continue;
        }
        if (a != 0)
        {
            ++ans;
            st.push(a);
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("XEPGACH.INP", "r", stdin);
    freopen("XEPGACH.OUT", "w", stdout);

    solve();
    return 0;
}