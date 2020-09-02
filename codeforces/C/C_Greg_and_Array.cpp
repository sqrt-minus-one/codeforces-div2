#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l[m + 1], r[m + 1], d[m + 1];
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i] >> d[i];
    int x[k + 1], y[k + 1];
    for (int i = 1; i <= k; i++)
        cin >> x[i] >> y[i];
    int ops[m + 1];
    memset(ops, 0, sizeof(ops));
    for (int i = 1; i <= k; i++)
    {
        ops[x[i]]++;
        if (y[i] < m)
            ops[y[i] + 1]--;
    }
    for (int i = 1; i <= m; i++)
        ops[i] += ops[i - 1];
    long long p[n + 1];
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= m; i++)
    {
        p[l[i]] += d[i] * 1ll * ops[i];
        if (r[i] < n)
            p[r[i] + 1] -= ops[i] * 1ll * d[i];
    }
    for (int i = 1; i <= n; i++)
        p[i] += p[i - 1];
    for (int i = 1; i <= n; i++)
        cout << a[i] + p[i] << ' ';
    return 0;
}