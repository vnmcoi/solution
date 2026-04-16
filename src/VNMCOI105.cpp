#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e4 + 5;
const long long INF = 0x3f3f3f3f;

int N, M, K, S, T;

struct edge
{
    int v, w, type;
};

struct vertical
{
    int u;
    long long w;
    int type;
};

struct compare
{
    bool operator()(const vertical &a, const vertical &b)
    {
        return a.w > b.w;
    }
};

vector<edge> adj[mxN];
int dist[mxN][2];

void dijkstra(int st)
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<vertical, vector<vertical>, compare> Q;
    dist[st][0] = 0;
    Q.push({st, dist[st][0], 0});
    while (Q.empty() == false)
    {
        vertical cur = Q.top();
        Q.pop();
        if (dist[cur.u][cur.type] != cur.w)
        {
            continue;
        }
        for (const edge &next : adj[cur.u])
        {
            if (cur.type + next.type <= 1 && cur.w + next.w < dist[next.v][cur.type + next.type])
            {
                dist[next.v][cur.type + next.type] = cur.w + next.w;
                Q.push({next.v, dist[next.v][cur.type + next.type], cur.type + next.type});
            }
        }
    }
}

void solve()
{
    cin >> N >> M >> K >> S >> T;
    for (int i = 1; i <= M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, 0});
    }
    for (int k = 1; k <= K; ++k)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, 1});
        adj[v].push_back({u, w, 1});
    }
    dijkstra(S);
    long long mn = min(dist[T][0], dist[T][1]);
    if (mn == INF)
    {
        cout << -1;
    }
    else
    {
        cout << mn;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DEXUAT.INP", "r", stdin);
    freopen("DEXUAT.OUT", "w", stdout);

    solve();
    return 0;
}