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
//first index such that f is true 
template<typename T,typename U>
T fstTrue(T lo, T hi, U f) {
    hi ++; assert(lo <= hi);
    while (lo < hi) {
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
//last index such that f is false
template<typename T,typename U>
T lstFalse(T lo, T hi, U f) {
    lo --; assert(lo <= hi);
    while (lo < hi) {
        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}

int main() 
{ 
    setIO();
    int t; cin>>t;
    while (t--){
        int n,m; cin>>n>>m;
        vi k(n+1);
        read1(k,n);
        vi c(m+1); read1(c,m);
        set<int> remaining;
        repL(i,1,m) remaining.insert(i);
        sort(all(k));
        ll ans = 0;
        repR(i,n,1){
            if (sz(remaining) == 0){
                ans += c[k[i]];
                continue;
            }
            int j = *remaining.begin();
            if (j < k[i]){
                ans += c[j];
                remaining.erase(j);
            }
            else {
                ans+=c[k[i]];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}