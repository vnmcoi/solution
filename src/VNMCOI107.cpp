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

#define MAX 227
int numNode, numExtra, dist[MAX][MAX];
vector<pair<int, int>> edges;

void noAnswer(void)
{
    cout << "-1 -1" << endl;
    exit(EXIT_SUCCESS);
}

void loadGraph(void)
{
    scanf("%d", &numNode);
    FOR(i, 1, numNode)
    FOR(j, 1, numNode) scanf("%d", &dist[i][j]);

    FOR(i, 1, numNode)
    if (dist[i][i] != 0) noAnswer();
    FOR(i, 1, numNode)
    FOR(j, 1, numNode) if (dist[i][j] != dist[j][i]) noAnswer();
    FOR(i, 1, numNode)
    FOR(j, 1, numNode) FOR(k, 1, numNode) if (dist[i][j] > dist[i][k] + dist[k][j]) noAnswer();
}

void createEdge(int u, int v, int d)
{
    int cur = u;
    REP(gspvh, d - 1)
    {
        int next = numNode + (++numExtra);
        edges.push_back(make_pair(cur, next));
        cur = next;
    }
    edges.push_back(make_pair(cur, v));
}

void process(void)
{
    FOR(i, 1, numNode)
    FOR(j, i + 1, numNode)
    {
        bool ok = false;
        FOR(k, 1, numNode)
        if (k != i && k != j && dist[i][j] == dist[i][k] + dist[k][j]) ok = true;
        if (!ok)
            createEdge(i, j, dist[i][j]);
    }

    printf("%d %d\n", numExtra, (int)edges.size());
    for (pair<int, int> &e : edges)
        if (e.fi > e.se)
            swap(e.fi, e.se);
    for (const pair<int, int> &e : edges)
        printf("%d %d\n", e.fi, e.se);
}

int main(void)
{
#ifdef ONLINE_JUDGE
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
#endif // ONLINE_JUDGE

    loadGraph();
    process();
    return 0;
}
