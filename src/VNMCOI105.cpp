#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()

#define MAX 1515
const int INF = (int)1e9 + 7;

int numRow, numCol, value[MAX][MAX];
int cnt[MAX], markedRow;
pair<int, int> cells[MAX * MAX];

void init(void)
{
    scanf("%d%d", &numRow, &numCol);
    int t = 0;
    FOR(i, 1, numRow)
    FOR(j, 1, numCol)
    {
        scanf("%d", &value[i][j]);
        cells[++t] = make_pair(i, j);
    }
}

bool Compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return value[a.fi][a.se] < value[b.fi][b.se];
}

void process(void)
{
    sort(cells + 1, cells + numRow * numCol + 1, Compare);

    int best = INF;

    int j = 0;
    FOR(i, 1, numRow * numCol)
    {
        if (i > 1)
        {
            int x = cells[i - 1].fi;
            if (--cnt[x] == 0)
                markedRow--;
        }
        while (markedRow < numRow)
        {
            if (++j > numRow * numCol)
                break;
            int x = cells[j].fi;
            if (cnt[x]++ == 0)
                markedRow++;
        }

        if (markedRow == numRow && j <= numRow * numCol)
            best = min(best, value[cells[j].fi][cells[j].se] - value[cells[i].fi][cells[i].se]);
    }

    printf("%d\n", best);
}

int main(void)
{
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    init();
    process();
    return 0;
}
