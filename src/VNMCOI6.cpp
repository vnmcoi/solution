#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("XEPGACH.INP", "r", stdin);
    freopen("XEPGACH.OUT", "w", stdout);

    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        while (st.empty() == false && st.top() > x)
        {
            st.pop();
        }
        if (st.empty() == false && st.top() == x)
        {
            continue;
        }
        if (x != 0)
        {
            ++ans;
            st.push(x);
        }
    }
    cout << ans;
    return 0;
}