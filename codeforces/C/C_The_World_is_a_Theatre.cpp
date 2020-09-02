#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    long long ans = 0;
    long long c[31][31];

    for (int i = 0; i <= 30; i++)
        for (int j = 0; j <= 30; j++)
            c[i][j] = 0;

    for (int i = 0; i <= 30; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for (int g = max(1, t - n); g <= min(t - 4, m); g++)
    {
        ans += c[m][g] * c[n][t - g];
    }
    cout << ans;
    return 0;
}