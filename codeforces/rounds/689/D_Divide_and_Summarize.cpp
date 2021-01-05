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
void solve(const vector<ll>& a, set<ll> &sums){
    if (sz(a) == 1) {
        sums.insert(a[0]);
        return;
    }
    if (sz(a) == 0 ) return;
    int m = a[0], M = a[0];
    int n = sz(a);
    ll sum = 0;
    rep(i,n){
        if (a[i] < m) m = a[i];
        if (a[i]>M) M = a[i];
        sum += a[i];
    }
    if (m == M){
        sums.insert(sum);
        return;
    }
    int mid = (m + M)/2;
    vector<ll> left,right;
    rep(i,n){
        if (a[i]<=mid) left.pb(a[i]);
        else right.pb(a[i]);
    }
    sums.insert(sum);
    
    solve(left,sums);
    solve(right,sums);
}
int main() 
{ 
    setIO();
    int t; cin>>t;
    while (t--){
        int n,q; cin>>n>>q;
        vector<ll> a(n);
        read(a,n);
        set<ll> sums;
        solve(a,sums);
        while (q--){
            ll s; cin >>s;
            if (sums.find(s) != sums.end()) cout<<"Yes\n";
            else cout<<"No\n";
        }
        sums.clear();
    }
    return 0;
}