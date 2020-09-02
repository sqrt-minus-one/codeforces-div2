#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        int target = 2 * n + p;
        vector<int> s1, s2;
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++)
            s1.push_back(i);
        while (target)
        {
            int v = s1[s1.size() - 1];
            s1.pop_back();
            s2.push_back(v);
            if (s1.size() <= target)
            {
                for (int u : s1)
                    ans.push_back({v, u});
                target -= s1.size();
            }
            else
            {
                for (int i = 0; i < target; i++)
                    ans.push_back({v, s1[i]});
                target = 0;
            }
        }
        for (auto r : ans)
            cout << r.first << ' ' << r.second << '\n';
    }
    return 0;
}