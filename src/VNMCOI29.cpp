#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = N; i >= 1; --i)
    {
        for (int j = i; j >= 1; --j)
        {
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}