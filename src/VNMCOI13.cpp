#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e4 + 5;

int N;

struct Rectangle
{
    int X1, Y1, X2, Y2;
    int A;
};

struct Event
{
    int x, type, id;
    bool operator<(const Event &other) const
    {
        if (x != other.x)
        {
            return x < other.x;
        }
        else
        {
            return type > other.type;
        }
    }
};

struct DisjointSetUnion
{
    int n;
    vector<int> par;
    vector<int> sz;

    DisjointSetUnion(int _n) : n(_n)
    {
        par.assign(n + 1, -1);
        sz.assign(n + 1, 1);
    }

    int find(int u)
    {
        return (par[u] == -1 ? u : par[u] = find(par[u]));
    }

    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return false;
        }
        if (sz[u] > sz[v])
        {
            swap(u, v);
        }
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

Rectangle R[mxN];
vector<Event> E;
long long sum[mxN];

bool check(const Rectangle &A, const Rectangle &B)
{
    return max(A.Y1, B.Y1) <= min(A.Y2, B.Y2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("LATGACH.INP", "r", stdin);
    freopen("LATGACH.OUT", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int X, Y, D, C;
        cin >> X >> Y >> D >> C;
        R[i] = {X, Y, X + D, Y + C, D * C};
        E.push_back({X, 1, i});
        E.push_back({X + D, -1, i});
    }
    sort(E.begin(), E.end());
    DisjointSetUnion dsu(N);
    set<pair<int, int>> st;
    for (vector<Event>::iterator itr = E.begin(); itr != E.end(); ++itr)
    {
        int i = itr->id;
        if (itr->type == 1)
        {
            int y = R[i].Y1 - 500;
            set<pair<int, int>>::iterator it = st.lower_bound({y, -1});
            for (; it != st.end(); ++it)
            {
                int j = it->second;
                if (R[j].Y1 > R[i].Y2)
                {
                    break;
                }
                if (check(R[i], R[j]) == true)
                {
                    dsu.merge(i, j);
                }
            }
            st.insert(make_pair(R[i].Y1, i));
        }
        else
        {
            st.erase(make_pair(R[i].Y1, i));
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x = dsu.find(i);
        sum[x] += R[i].A;
        ans = max(ans, sum[x]);
    }
    cout << ans;
    return 0;
}