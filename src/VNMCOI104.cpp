#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()

#define prev T120HLE
#define next HLE02T1

template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

struct Edge
{
    int u, v;
    long long value;

    Edge(int _u = 0, int _v = 0)
    {
        u = _u;
        v = _v;
        value = 0;
    }
};

struct DisjointSet
{
    vector<int> lab;

    DisjointSet(int n = 0)
    {
        lab.assign(n + 1, -1);
    }

    int find(int x)
    {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

    bool join(int u, int v)
    {
        int x = find(u), y = find(v);
        if (x == y)
            return false;

        if (lab[x] > lab[y])
            swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

#define MAX 200200
#define LOG 18
const long long INF = (long long)1e18 + 7LL;

int numNode, numEdge, numSpecial, numQuery;
bool special[MAX];
Edge edges[MAX];
vector<pair<int, int>> adj[MAX];
vector<pair<int, long long>> treeAdj[MAX];
long long dist[MAX];
int high[MAX];
pair<int, long long> par[MAX][LOG + 1];

void loadGraph(void)
{
    scanf("%d%d", &numNode, &numEdge);
    FOR(i, 1, numEdge)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
        edges[i] = Edge(u, v);
    }

    scanf("%d", &numSpecial);
    REP(gspvh, numSpecial)
    {
        int x;
        scanf("%d", &x);
        special[x] = true;
    }
}

void dijkstra(void)
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

#define PUSH(u) q.push(make_pair(dist[u], u))
    FOR(i, 1, numNode)
    if (special[i])
    {
        dist[i] = 0;
        PUSH(i);
    }

    while (!q.empty())
    {
        int u = q.top().se;
        long long d = q.top().fi;
        q.pop();
        if (d != dist[u])
            continue;

        for (const pair<int, int> &e : adj[u])
        {
            int v = e.fi, c = e.se;
            if (minimize(dist[v], dist[u] + c))
                PUSH(v);
        }
    }
}

bool CompareEdge(const int &x, const int &y)
{
    return edges[x].value > edges[y].value;
}
void kruskal(void)
{
    FOR(i, 1, numEdge)
    edges[i].value = min(dist[edges[i].u], dist[edges[i].v]);
    vector<int> indices;
    FOR(i, 1, numEdge)
    indices.push_back(i);
    sort(ALL(indices), CompareEdge);

    DisjointSet dsu(numNode);
    for (int i : indices)
    {
        int u = edges[i].u, v = edges[i].v;
        if (dsu.join(u, v))
        {
            treeAdj[u].push_back(make_pair(v, edges[i].value));
            treeAdj[v].push_back(make_pair(u, edges[i].value));
        }
    }
}

void dfs(int u)
{
    for (const pair<int, long long> &e : treeAdj[u])
        if (e.fi != par[u][0].fi)
        {
            int v = e.fi;
            par[v][0] = make_pair(u, e.se);
            high[v] = high[u] + 1;
            dfs(v);
        }
}

void setupLCK(void)
{
    high[0] = -1;
    dfs(1);

    FOR(j, 1, LOG)
    FOR(i, 1, numNode)
    {
        par[i][j].fi = par[par[i][j - 1].fi][j - 1].fi;
        par[i][j].se = min(par[i][j - 1].se, par[par[i][j - 1].fi][j - 1].se);
    }
}

long long query(int u, int v)
{
    if (u == v)
        return dist[u];
    if (high[v] > high[u])
        swap(u, v);

    long long res = INF;
    FORD(i, LOG, 0)
    if (high[par[u][i].fi] >= high[v])
    {
        minimize(res, par[u][i].se);
        u = par[u][i].fi;
    }

    if (u == v)
        return res;

    FORD(i, LOG, 0)
    if (par[u][i].fi != par[v][i].fi)
    {
        minimize(res, par[u][i].se);
        minimize(res, par[v][i].se);
        u = par[u][i].fi;
        v = par[v][i].fi;
    }

    minimize(res, par[u][0].se);
    minimize(res, par[v][0].se);
    return res;
}

void process(void)
{
    scanf("%d", &numQuery);
    REP(gspvh, numQuery)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", query(u, v));
    }
}

int main(void)
{
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

#ifdef ONLINE_JUDGE
    freopen("exit.inp", "r", stdin);
    freopen("exit.out", "w", stdout);
#endif // ONLINE_JUDGE

    loadGraph();
    dijkstra();
    kruskal();
    setupLCK();
    process();
    return 0;
}
