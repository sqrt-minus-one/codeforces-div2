#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main()
{
    int n;
    cin >> n;
    vector<ii> points;
    vector<ii> rpoints;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(ii(x, y));
        rpoints.push_back(ii(y, x));
        
    }
    long long ans = 0;
    int cnt = 1;
    sort(points.begin(), points.end());
    for (int i = 1; i < n; i++)
    {
        if (points[i].first == points[i - 1].first)
        {
            cnt++;
        }
        else
        {
            ans += cnt *1ll* (cnt - 1) / 2;
            cnt = 1;
        }
    }
    ans += cnt *1ll* (cnt - 1) / 2;
    cnt = 1;
    sort(rpoints.begin(), rpoints.end());
    for (int i = 1; i < n; i++)
    {
        if (rpoints[i].first == rpoints[i - 1].first)
        {
            cnt++;
        }
        else
        {
            ans += cnt *1ll* (cnt - 1) / 2;
            cnt = 1;
        }
    }
    ans += cnt *1ll* (cnt - 1) / 2;
    cnt=1;
    for (int i=1;i<n;i++){
        if (points[i].second == points[i - 1].second && points[i].first == points[i - 1].first) cnt++;
        else {
            ans-=cnt *1ll* (cnt - 1) / 2;
            cnt=1;
        }
    }
    ans-= cnt *1ll* (cnt - 1) / 2;
    cout << ans;
    return 0;
}