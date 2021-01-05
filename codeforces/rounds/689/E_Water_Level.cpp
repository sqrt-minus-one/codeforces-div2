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

int main() 
{ 
    setIO();
    ll k,l,r,t,x,y; cin>>k>>l>>r>>t>>x>>y;
    if (y == x){
        if (k + y <= r) cout<<"Yes\n";
        else {
            if (k - x >= l) cout<<"Yes\n";
            else cout<<"No";
        }
    }
    else if (y < x){
        if (k + y <= r){
            ll d = (k - l)/(x - y);
            if (d < t) cout<<"No";
            else cout<<"Yes";
        }
        else {
            if (k - x >= l){
                ll d = (k - l - x)/( x - y);
                d++;
                if (d < t) cout<<"No";
                else cout<<"Yes";
            }
            else cout<<"No";
        }
    }
    else {
        while (t > 0){
            if (k + y <= r){
                k+=y;
                ll q = y / x;
                ll n = y%x;
                t -= q;
                k -= x*q;
            }
            else {
                ll d = (k-l)/x;
                if (d < t){
                    t -= d;
                    k -= d*x;
                    if (k + y > r) {
                        cout<<"No";
                        return 0;
                    }
                    else k+=y;
                }
                else {
                    cout<<"Yes";
                    return 0;
                }
            }
        }
        cout<<"Yes";
    }
    return 0;
}