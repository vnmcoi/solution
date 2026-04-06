#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()

const int MOD = (int)1e9 + 7;
void add(int &x, const int &y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

#define MAX_STATE 33333
#define MAX_VALUE 220797
const int SPECIAL = 180;

bool notPrime[SPECIAL + 1];
vector<int> primes;

int numQuery, L, R;
vector<int> valuesL, valuesR;
bool haveL[MAX_VALUE], haveR[MAX_VALUE];
int nextL[SPECIAL + 1][MAX_STATE], nextR[SPECIAL + 1][MAX_STATE];

int dpL[MAX_STATE], dpR[MAX_STATE];
bool markL[MAX_STATE], markR[MAX_STATE];
vector<int> statesL, statesR;
int coeffL[MAX_STATE], coeffR[MAX_STATE];
int tmp[MAX_STATE];

vector<int> small, large;

void eratosthene(void)
{
    REP(i, 2)
    notPrime[i] = true;
    for (int i = 2; 1LL * i * i <= SPECIAL; i++)
        if (!notPrime[i])
            for (int j = i * i; j <= SPECIAL; j += i)
                notPrime[j] = true;
    FOR(i, 2, SPECIAL)
    if (!notPrime[i])
        primes.push_back(i);
}

void genValue(int pos, long long cur)
{
    if (pos >= (int)primes.size())
    {
        if (cur <= L)
        {
            int tmp = L / cur;
            if (tmp < MAX_VALUE)
                haveL[tmp] = true;
            else
                valuesL.push_back(tmp);
        }
        if (cur <= R)
        {
            int tmp = R / cur;
            if (tmp < MAX_VALUE)
                haveR[tmp] = true;
            else
                valuesR.push_back(tmp);
        }
        return;
    }

    int p = primes[pos];
    while (cur <= R)
    {
        genValue(pos + 1, cur);
        cur *= p;
    }
}

void calcNext(bool have[], vector<int> &values, int next[][MAX_STATE])
{
    REP(i, MAX_VALUE)
    if (have[i])
        values.push_back(i);
    sort(ALL(values));
    values.resize(unique(ALL(values)) - values.begin());
    assert(values.size() < MAX_STATE);

    FOR(i, 1, SPECIAL)
    REP(j, values.size())
    {
        if (i > values[j])
        {
            next[i][j] = -1;
            continue;
        }

        int tmp = values[j] / i;
        int id = lower_bound(ALL(values), tmp) - values.begin();
        assert(id < (int)values.size() && values[id] == tmp);
        next[i][j] = id;
    }
}

void initDPArray(const vector<int> &values, int dp[], bool mark[], vector<int> &states)
{
    memset(dp, 0, (MAX_STATE - 1) * sizeof(int));
    memset(mark, false, (MAX_STATE - 1) * sizeof(bool));
    states.clear();

    int pos = values.size() - 1;
    dp[pos] = 1;
    mark[pos] = true;
    states.push_back(pos);
}

void updateDPArray(int newVal, int next[][MAX_STATE], int dp[], bool mark[], vector<int> &states)
{
    for (int x : states)
        tmp[x] = dp[x];
    REP(i, states.size())
    {
        int curState = states[i];
        int newState = next[newVal][curState];
        if (newState < 0)
            continue;

        add(dp[newState], tmp[curState]);
        if (dp[newState] > 0 && !mark[newState])
        {
            mark[newState] = true;
            states.push_back(newState);
        }
    }
}

void addSmallElement(int newVal)
{
    updateDPArray(newVal, nextL, dpL, markL, statesL);
    updateDPArray(newVal, nextR, dpR, markR, statesR);
    small.push_back(newVal);
}
void removeSmallElement(int oldVal)
{
    int id = 0;
    while (id < (int)small.size() && small[id] != oldVal)
        id++;
    assert(id < (int)small.size());

    swap(small[id], small.back());
    small.pop_back();

    initDPArray(valuesL, dpL, markL, statesL);
    initDPArray(valuesR, dpR, markR, statesR);

    vector<int> tmpSmall = small;
    small.clear();
    sort(ALL(tmpSmall), greater<int>());
    for (int x : tmpSmall)
        addSmallElement(x);
}

void updateCoeff(int value, int delta)
{
    if (value <= L)
    {
        int tmp = value;
        int pos = lower_bound(ALL(valuesL), tmp) - valuesL.begin();
        if (pos < (int)valuesL.size())
            coeffL[pos] += delta;
    }
    if (value <= R)
    {
        int tmp = value;
        int pos = lower_bound(ALL(valuesR), tmp) - valuesR.begin();
        if (pos < (int)valuesR.size())
            coeffR[pos] += delta;
    }

    REP(i, large.size())
    {
        if (1LL * large[i] * value <= L)
        {
            int tmp = large[i] * value;
            int pos = lower_bound(ALL(valuesL), tmp) - valuesL.begin();
            if (pos < (int)valuesL.size())
                coeffL[pos] += delta;
        }
        if (1LL * large[i] * value <= R)
        {
            int tmp = large[i] * value;
            int pos = lower_bound(ALL(valuesR), tmp) - valuesR.begin();
            if (pos < (int)valuesR.size())
                coeffR[pos] += delta;
        }
    }

    REP(i, large.size())
    FOR(j, i + 1, (int)large.size() - 1)
    {
        if (1LL * large[i] * large[j] <= L / value)
        {
            int tmp = large[i] * large[j] * value;
            int pos = lower_bound(ALL(valuesL), tmp) - valuesL.begin();
            if (pos < (int)valuesL.size())
                coeffL[pos] += delta;
        }
        if (1LL * large[i] * large[j] <= R / value)
        {
            int tmp = large[i] * large[j] * value;
            int pos = lower_bound(ALL(valuesR), tmp) - valuesR.begin();
            if (pos < (int)valuesR.size())
                coeffR[pos] += delta;
        }
    }
}

void addLargeElement(int newVal)
{
    updateCoeff(newVal, +1);
    large.push_back(newVal);
}
void removeLargeElement(int oldVal)
{
    int id = 0;
    while (id < (int)large.size() && large[id] != oldVal)
        id++;
    assert(id < (int)large.size());

    swap(large[id], large.back());
    large.pop_back();

    updateCoeff(oldVal, -1);
}

int getResult(int coeff[], const vector<int> &values, int dp[])
{
    int sum = 0, res = 0;
    FORD(i, (int)values.size() - 1, 0)
    {
        add(sum, dp[i]);
        res = (res + 1LL * sum * coeff[i]) % MOD;
    }
    return res;
}

void process(void)
{
    int numQuery;
    cin >> numQuery >> L >> R;
    L--;

    genValue(0, 1);
    calcNext(haveL, valuesL, nextL);
    calcNext(haveR, valuesR, nextR);

    initDPArray(valuesL, dpL, markL, statesL);
    initDPArray(valuesR, dpR, markR, statesR);
    coeffL[0] = coeffR[0] = 1;

    REP(faker, numQuery)
    {
        string type;
        int value;
        cin >> type >> value;
        if (type == "+")
        {
            if (value <= SPECIAL)
                addSmallElement(value);
            else
                addLargeElement(value);
        }
        else
        {
            if (value <= SPECIAL)
                removeSmallElement(value);
            else
                removeLargeElement(value);
        }

        int resL = getResult(coeffL, valuesL, dpL);
        int resR = getResult(coeffR, valuesR, dpR);

        printf("%d\n", (resR - resL + MOD) % MOD);
    }
}

int main(void)
{
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    eratosthene();
    process();

    return 0;
}
