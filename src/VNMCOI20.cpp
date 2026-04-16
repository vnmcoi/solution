#include <bits/stdc++.h>
using namespace std;

double A;

void solve()
{
    cin >> A;
    if (A >= 9.0)
    {
        cout << "VERY TOXIC";
    }
    else if (A >= 5.0 && A <= 8.9)
    {
        cout << "TOXIC";
    }
    else
    {
        cout << "SAFE";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}