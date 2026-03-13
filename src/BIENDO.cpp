#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6 + 5;

int N;
int A[mxN];
int L[mxN], R[mxN];
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("BIENDO.INP", "r", stdin);
    freopen("BIENDO.OUT", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        while (st.empty() == false && A[st.top()] <= A[i])
        {
            st.pop();
        }
        if (st.empty() == true)
        {
            L[i] = i;
        }
        else
        {
            L[i] = i - st.top();
        }
        st.push(i);
    }
    while (st.empty() == false)
    {
        st.pop();
    }
    for (int i = N; i >= 1; --i)
    {
        while (st.empty() == false && A[st.top()] < A[i])
        {
            st.pop();
        }
        if (st.empty() == true)
        {
            R[i] = N - i + 1;
        }
        else
        {
            R[i] = st.top() - i;
        }
        st.push(i);
    }
    while (st.empty() == false)
    {
        st.pop();
    }
    long long mx = 0;
    for (int i = 1; i <= N; ++i)
    {
        mx += 1LL * A[i] * L[i] * R[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        while (st.empty() == false && A[st.top()] >= A[i])
        {
            st.pop();
        }
        if (st.empty() == true)
        {
            L[i] = i;
        }
        else
        {
            L[i] = i - st.top();
        }
        st.push(i);
    }
    while (st.empty() == false)
    {
        st.pop();
    }
    for (int i = N; i >= 1; --i)
    {
        while (st.empty() == false && A[st.top()] > A[i])
        {
            st.pop();
        }
        if (st.empty() == true)
        {
            R[i] = N - i + 1;
        }
        else
        {
            R[i] = st.top() - i;
        }
        st.push(i);
    }
    long long mn = 0;
    for (int i = 1; i <= N; ++i)
    {
        mn += 1LL * A[i] * L[i] * R[i];
    }
    cout << mx - mn;
    return 0;
}