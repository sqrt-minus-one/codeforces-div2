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
vi get_bin(ll x){
    vi po(60,0);
    int p = 0;
    while(x){
        if (x % 2) po[p]++;
        x >>= 1;
        p++;
    }
    return po;
}

int main() 
{ 
    setIO();
    int t; cin>>t;
    int occ[60];
    ll pow_2[60];
    rep(i,60) pow_2[i] = (1LL<<i) % MOD;
    while (t--){
        int n; cin>>n;
        ll x[n];
        read(x,n);
        memset(occ,0,sizeof(occ));
        ll sum = 0;

        rep(i,n){
            sum += x[i];
            sum %= MOD;
            auto po = get_bin(x[i]);
            rep(k,60) occ[k] += po[k];
        }

        ll ans = 0;

        rep(j,n){
            ll f = 0;
            ll g = 0;
            auto po = get_bin(x[j]);
            rep(i,60){
                if (po[i]){
                    ll ns = n - occ[i];
                    f = (f + pow_2[i] * ns) % MOD;
                }
                else {
                    ll s = occ[i];
                    g = (g + pow_2[i]*s) % MOD;
                }
            }
            ans += ((sum + f)%MOD *(MOD + sum -g)%MOD)%MOD;
            ans %= MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}