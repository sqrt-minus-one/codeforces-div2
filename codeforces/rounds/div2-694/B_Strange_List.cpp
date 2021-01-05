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
        int n,x; cin>>n>>x;
        vector<pair<ll,ll>> a(1);
        a[0].F = 1;
        cin>>a[0].S;
        rep(i,n-1){
            ll y; cin>>y;
            if (y == a[sz(a) - 1].S) a[sz(a) - 1].F++;
            else a.pb({1,y});
        }
        rep(i,sz(a)){
            ll cnt = a[i].F;
            ll q = a[i].S;
            if (q % x == 0){
                a.pb({cnt * x, q / x});
            }
            else {
                break;
            }
        }
        ll ans = 0;
        rep(i,sz(a)) ans += a[i].F * a[i].S;
        cout<<ans<<endl;
    }

    return 0;
}