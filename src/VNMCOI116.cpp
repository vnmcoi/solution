#include <bits/stdc++.h>
using namespace std;

int N, M;
multiset<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        int h;
        cin >> h;
        st.insert(h);
    }
    for (int i = 1; i <= M; ++i)
    {
        int t;
        cin >> t;
        multiset<int>::iterator itr = st.upper_bound(t);
        if (itr == st.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            --itr;
            cout << *itr << '\n';
            st.erase(itr);
        }
    }
    return 0;
}