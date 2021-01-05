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
    int t; cin>>t;
    while (t--){
        int c[3]; read(c,3);
        int a[5]; read(a,5);
        if (c[0] < a[0] || c[1] < a[1] || c[2] < a[2]) cout<<"No\n";
        else {
            c[0] -= a[0];
            c[1] -= a[1];
            c[2] -= a[2];
            if (a[3] <= c[0]) c[0] -= a[3],a[3] = 0;
            else {
                a[3] -= c[0];
                c[0] = 0;
                if (a[3] > c[2]) {
                    cout<<"No\n"; continue;
                }
                else c[2] -= a[3], a[3] = 0;
            }
            if (a[4] <= c[1]) c[1] -= a[4],a[4] = 0;
            else {
                a[4] -= c[1];
                c[1] = 0;
                if (a[4] > c[2]) {
                    cout<<"No\n";
                    continue;
                }
            }
            cout<<"Yes\n";
        }
    }
    return 0;
}