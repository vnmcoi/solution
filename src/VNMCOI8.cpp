#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

struct Value
{
    int a, b;
};

int N, M;
Value A[mxN];

int check(int x, int y)
{
    return (A[x].a != A[y].a ? A[x].a > A[y].a : A[x].b < A[y].b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("XEPHANG.INP", "r", stdin);
    freopen("XEPHANG.OUT", "w", stdout);

    cin >> N >> M;
    unordered_set<int> st;
    st.reserve(1e5);
    while (M--)
    {
        int t, p;
        cin >> t >> p;
        A[t].a++;
        A[t].b += p;
        if (t != 1)
        {
            if (check(t, 1) == true)
            {
                st.insert(t);
            }
        }
        else
        {
            vector<int> team;
            for (unordered_set<int>::iterator itr = st.begin(); itr != st.end(); ++itr)
            {
                if (check(*itr, 1) == false)
                {
                    team.push_back(*itr);
                }
            }
            for (vector<int>::iterator itr = team.begin(); itr != team.end(); ++itr)
            {
                st.erase(*itr);
            }
        }
        cout << (int)st.size() + 1 << '\n';
    }
    return 0;
}