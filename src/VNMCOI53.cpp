#include <bits/stdc++.h>
using namespace std;

const int mxN = 100 + 5;

const int moveX[] = {0, 1, 0, -1};
const int moveY[] = {1, 0, -1, 0};

int N, M;
int A[mxN][mxN];

bool check(int x, int y)
{
    return 1 <= x && x <= N && 1 <= y && y <= M && A[x][y] == 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int i = 1, j = 1, cnt = 0, k = 0;
    while (cnt < N * M)
    {
        A[i][j] = ++cnt;
        i += moveX[k];
        j += moveY[k];
        if (check(i, j) == false)
        {
            i -= moveX[k];
            j -= moveY[k];
            k = ++k % 4;
            i += moveX[k];
            j += moveY[k];
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}