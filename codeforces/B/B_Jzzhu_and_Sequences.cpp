#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1000000007
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define repL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define repR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first 
#define S second 
#define pb push_back 
#define pob pop_back 
#define read(n,a) rep(i,n) cin>>a[i]
#define write(n,a,s) rep(i,n) cout<<a[i]<<s;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    ll x,y; cin>>x>>y;
    int n; cin>>n;
    ll ans[6]={(x-y+2*mod) % mod,(x+mod)%mod,(y+mod)%mod,(y-x+2*mod) % mod,(-x+mod)%mod,(-y+mod)%mod};
    cout<<ans[n%6];
    
    return 0;
}