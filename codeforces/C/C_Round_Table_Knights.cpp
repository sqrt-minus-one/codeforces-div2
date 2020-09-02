#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    bool good = false;
    for (int i = 3; i <= n; i++)
    {
        if (n % i != 0)
            continue;
        int k = n / i;
        for (int j = 0; j < k; j++)
        {
            if (!p[j])
                continue;
            int x = j + k;
            for (; (x != j) && p[x]; x = (x + k) % n);
            if (x == j)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}