#include <bits/stdc++.h>
using namespace std;

string S;
int cnt_A, cnt_a, cnt_no;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);

    cin >> S;
    int N = (int)S.length();
    long long ans = 0;
    int j = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] >= 'A' && S[i] <= 'Z')
        {
            ++cnt_A;
        }
        else if (S[i] >= 'a' && S[i] <= 'z')
        {
            ++cnt_a;
        }
        else
        {
            ++cnt_no;
        }
        while (cnt_A != 0 && cnt_a != 0 && cnt_no != 0 && i - j + 1 >= 6)
        {
            ans += N - i;
            if (S[j] >= 'A' && S[j] <= 'Z')
            {
                --cnt_A;
            }
            else if (S[j] >= 'a' && S[j] <= 'z')
            {
                --cnt_a;
            }
            else
            {
                --cnt_no;
            }
            ++j;
        }
    }
    cout << ans;
    return 0;
}