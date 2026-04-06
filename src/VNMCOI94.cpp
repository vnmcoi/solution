#include <bits/stdc++.h>
using namespace std;

const int mxA = 1e5 + 5;

int N;
vector<int> B;
bitset<mxA> snt;

void era(void)
{
    snt.set();
    snt[0] = snt[1] = false;
    for (int i = 2; i * i <= 1e9; ++i)
    {
        if (snt[i] == true)
        {
            for (int j = i * i; j <= 1e5; j += i)
            {
                snt[j] = false;
            }
        }
    }
    int i = 2;
    while (true)
    {
        if (snt[i] == true)
        {
            B.push_back(i * i);
            if (i * i >= 1e9)
            {
                return;
            }
        }
        ++i;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);
    era();
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int A;
        cin >> A;
        cout << *lower_bound(B.begin(), B.end(), A) << ' ';
    }
    return 0;
}