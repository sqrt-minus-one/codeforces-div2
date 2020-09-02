#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define rep(a, c) for (int (a) = 0; (a) < (c); (a)++) 
#define repL(a, b, c) for (int (a) = b; (a) < c; (a)++) 
#define repR(a, b, c) for (int (a) = (b); (a) > (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first 
#define S second 
#define pb push_back 
#define pob pop_back 
#define read(n,a) rep(i,n) cin>>a[i]
#define write(n,a,s) rep(i,n) cout<<a[i]<<s;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n,m; cin>>n>>m;
    set<int> knights;
    repL(i,1,n+1) knights.insert(i);
    int ans[n+1];
    memset(ans,0,sizeof(ans));

    rep(i,m){
        int l,r,x; cin>>l>>r>>x;
        auto it1 = knights.lower_bound(l);
        auto it2 = knights.upper_bound(r);
        for (auto i = it1; i != it2;i++){
            if (*i==x) continue;
            ans[*i]=x;
        }
        knights.erase(it1,it2);
        knights.insert(x);
    }
    repL(i,1,n+1) cout<<ans[i]<<' ';
    return 0;
}