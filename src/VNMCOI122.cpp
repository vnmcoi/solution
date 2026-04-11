#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N;

struct Point
{
    int x, y, z;
    struct Compare
    {
        bool operator()(const Point &a, const Point &b)
        {
            if (a.x == b.x)
            {
                if (a.y == b.y)
                {
                    return a.z < b.z;
                }
                return a.y < b.y;
            }
            return a.x < b.x;
        }
    };
};

Point A[mxN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
    sort(A + 1, A + 1 + N, Point::Compare());
    for (int i = 1; i <= N; ++i)
    {
        cout << A[i].x << ' ' << A[i].y << ' ' << A[i].z << '\n';
    }
    return 0;
}