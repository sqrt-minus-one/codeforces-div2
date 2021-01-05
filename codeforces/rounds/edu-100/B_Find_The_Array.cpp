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
ll solve(ll b,vi& a){
    int n = sz(a);
    ll sum = abs(a[0] - b);
    repL(i,1,n-1){
        if (a[i] == b) continue;
        if (a[i] > b){
            int k = a[i] / b;
            ll b1 = k*b;
            ll b2 = b1 + b;
            if ( abs(a[i] - b1) > abs(a[i] - b2) ) swap(b1,b2);
            b = b1;
            sum += abs(a[i] - b);
        }
    }
    return sum;
}
int main() 
{ 
    setIO();
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int a[n];
        read(a,n);
        
    }
    return 0;
}