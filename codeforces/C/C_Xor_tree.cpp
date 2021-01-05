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
        freopen((name+".out").c_str(), "w", stdout);
    }
}
vi g[N];
vi ans;
void solve(int u, int p, bool odd, bool even, bool parity, const vi& goal, vi& current){
    if ((even && !parity) || (odd && parity) ) {
        current[u] ^= 1;
    }
    if (current[u] != goal[u]){
        current[u] ^= 1;
        if (parity) odd = !odd;
        else even = !even;
        ans.pb(u);
    }
    trav(v,g[u]){
        if (v == p) continue;
        solve(v, u, odd, even, !parity, goal, current);
    }
}
int main() 
{ 
    setIO();
    int n; cin>>n;
    vi goal(n+1), current(n+1);
    rep(i,n-1){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    read1(current,n);
    read1(goal,n);
    solve(1,-1,false,false,0,goal,current);
    cout<<sz(ans)<<endl;
    write(ans,sz(ans),endl);
    return 0;
}