#include <bits/stdc++.h>
using namespace std;

const int mxN = 10 + 5;
const int OFFSET = 10;

int N;
bool visY[mxN];
bool Left[mxN + OFFSET];
bool Right[mxN + OFFSET];
bool A[mxN][mxN];
int ans = 0;

void wayslui(int pos)
{
    if (pos == 8 + 1)
    {
        ++ans;
        return;
    }
    for (int i = 1; i <= 8; ++i)
    {
        if (visY[i] == false && Left[pos - i + OFFSET] == false && Right[pos + i] == false && A[pos][i] == false)
        {
            visY[i] = true;
            Left[pos - i + OFFSET] = true;
            Right[pos + i] = true;
            wayslui(pos + 1);
            visY[i] = false;
            Left[pos - i + OFFSET] = false;
            Right[pos + i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 8; ++i)
    {
        string S;
        cin >> S;
        for (int j = 1; j <= 8; ++j)
        {
            if (S[j - 1] == '*')
            {
                A[i][j] = true;
            }
        }
    }
    wayslui(1);
    cout << ans;
    return 0;
}