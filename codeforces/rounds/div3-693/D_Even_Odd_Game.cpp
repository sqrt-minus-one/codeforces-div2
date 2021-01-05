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
#define write(a,n,s) rep(i,n) cout<<a[i]<<s; cout<<endl;
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
        int n; cin>>n;
        int a[n]; read(a,n);
        sort(a,a+n);
        reverse(a,a+n);
        ll score_bob = 0, score_alice = 0;
        
        rep(i,n){
            if (i % 2){
                score_bob += (a[i] %2 == 1) ? a[i] : 0;
            }
            else {
                score_alice += (a[i] %2 == 0)? a[i]:0;
            }
        }
        if (score_alice > score_bob) cout<<"Alice\n";
        else if (score_alice == score_bob) cout<<"Tie\n";
        else cout<<"Bob\n";
    }
    return 0;
}