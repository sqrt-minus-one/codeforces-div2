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
        ll n,x; cin>>n>>x;
        vector<ll> a(n);
        read(a,n);
        ll max_b = 0;
        rep(i,n) {
            max_b += a[i] / x;
            if (a[i] % x) max_b++; 
        }
        vector<ll> b;
        b.pb(a[0]);
        repL(i,1,n-1){
            ll r1 = a[i] % x;
            ll r2 = b[sz(b) - 1] % x;
            if (r1 && r2 && r1 + r2 <= x){
                b[sz(b) - 1] += a[i];
            }
            else {
                b.pb(a[i]);
            }
        }
        ll min_b = 0;
        trav(r,b) {
            min_b += r / x;
            if (r % x) min_b ++;
        }
        
        cout<<min_b<<' '<<max_b<<endl;
    }
    return 0;
}