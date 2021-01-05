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
using pi = pair<ll, ll>;
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

int main() 
{ 
    setIO();
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        map<pi,ll[2]> wtf;
        rep(i,n){
            pi a; cin>>a.F>>a.S;
            pi u; cin>>u.F>>u.S;

            pi r = {u.F - a.F,u.S - a.S};

            ll d = __gcd(r.F,r.S);
            int dir = ((r.S>0) || (r.S == 0 && r.F > 0));
            r.F /= d;
            r.S /= d;
            if (wtf.find(r) == wtf.end()) wtf[r][0] = 0, wtf[r][1]=0;
            wtf[r][dir]++;
        }

        ll ans = 0;
        trav(nani,wtf){
            ans += nani.second[0] *1ll* nani.second[1];
        }
        cout<<ans<<endl;
    }
    return 0;
}