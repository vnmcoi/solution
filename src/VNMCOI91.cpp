#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

int N, Q;
pair<int, int> A[mxN];

int lb(int val, int l, int r, int type)
{
    if (type == 1)
    {
        int lo = l - 1;
        int hi = r + 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            if (val <= A[mid].first)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        return hi;
    }
    else
    {
        int lo = l - 1;
        int hi = r + 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            if (val <= A[mid].second)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        return hi;
    }
}

int ub(int val, int l, int r, int type)
{
    if (type == 1)
    {
        int lo = l - 1;
        int hi = r + 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            if (A[mid].first <= val)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
    else
    {
        int lo = l - 1;
        int hi = r + 1;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;
            if (A[mid].second <= val)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A + 1, A + 1 + N);
    while (Q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int ll = lb(x, 1, N, 1);
        int rr = ub(x, 1, N, 1);
        int lll = lb(l, ll, rr, 2);
        int rrr = ub(r, ll, rr, 2);
        cout << rrr - lll + 1 << '\n';
    }
    return 0;
}