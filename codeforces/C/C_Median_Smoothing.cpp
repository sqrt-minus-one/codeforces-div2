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

int main() 
{ 
    setIO();
    int n; cin>>n;
    vi a(n+1);
    read(a,n);
    a[n] = a[n-1];
    int i = 0;
    int ans = 0;
    vector<pi> alt;
    repL(j,1,n){
        if (a[j] == a[j-1]){
            //segment [i,j-1] alternates
            alt.pb({i,j-1});
            i=j;
        }
    }
    trav(x,alt){
        int l = x.F, r = x.S;
        if (r - l <= 1) continue;
        ans = max(ans, (r - l)/2);
        if (a[l] == a[r]){
            repL(k,l,r) a[k] = a[l];
        }
        else {
            repL(k,l,r){
                if (k - l + 1 <= (r - l + 1)/2) a[k] = a[l];
                else a[k] = a[r];
            }
        }
    }
    cout<<ans<<endl;
    write(a,n," ");
    return 0;
}