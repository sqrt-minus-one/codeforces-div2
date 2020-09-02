#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define repL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define repR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
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
int m;
vi g[N];
bool cats[N];
ll dfs(int u, int par, int cnt){
    if (cats[u]) cnt++;
    else cnt=0;
    if (cnt > m) return 0;
    if (g[u].size() == 1 && u!=1) return 1;
    ll ans = 0;
    for (auto v : g[u]){
        if (v == par) continue;
        ans+=dfs(v,u,cnt);
    }
    return ans;
}

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin>>n>>m;
    rep(i,n) cin>>cats[i+1];
    rep(i,n-1){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    cout<<dfs(1,0,0);
    return 0;
}