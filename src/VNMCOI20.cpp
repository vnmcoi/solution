#include <bits/stdc++.h>
using namespace std;

double A;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
    return 0;
}