#include <bits/stdc++.h>
using namespace std;

int A, B, C;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    cout << 1LL * A * B % C;
    return 0;
}