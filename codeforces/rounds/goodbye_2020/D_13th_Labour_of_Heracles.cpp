#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define mod 1e9 + 7
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define repL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define repR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define trav(x,a) for (auto& x: a)
using ll = long long int; 
using vi = vector<int>;
using pi = pair<int, int>;
#define F first
#define S second
#define pb push_back 
#define pob pop_back
#define read(a,n) rep(i,n) cin>>a[i]
#define read1(a,n) repL(i,1,n) cin>>a[i]
#define write(a,n,s) rep(i,n) cout<<a[i]<<s;
const int N = 100010;
const int MOD = 1e9+7;
const ll INF = 1e18;
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        //freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() 
{ 
    setIO();
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        ll ans =0;
        ll w[n+1];
        read1(w,n);
        int deg[n+1];
        memset(deg,0,sizeof(deg));
        rep(i,n-1){
            int u,v; cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        priority_queue<pair<pi,int>> q;
        repL(i,1,n){
            ans+=w[i];
            if (deg[i] == 1) continue;
            q.push({{w[i],deg[i]},i});
        }
        cout<<ans<<' ';
        rep (i,n-2){
            auto x = q.top(); q.pop();
            int u = x.second;
            ans += x.F.F;
            deg[u]--;
            if (deg[u] > 1){
                q.push({{w[u],deg[u]},u});
            }
            cout<<ans<<' ';
        }
        cout<<endl;
    }
    return 0;
}