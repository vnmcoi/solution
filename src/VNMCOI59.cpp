#include <bits/stdc++.h>
using namespace std;

char C;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> C;
    if (C >= 'a' && C <= 'z')
    {
        cout << (char)(C - 'a' + 'A');
    }
    else if (C >= 'A' && C <= 'Z')
    {
        cout << (char)(C - 'A' + 'a');
    }
    return 0;
}