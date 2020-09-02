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
    int n,m; cin>>n>>m;
    int a[n][m]; rep(i,n) rep(j,m) cin>>a[i][j];
    bool is_prime[100005]; memset(is_prime,true, sizeof(is_prime));
    vi primes;
    repL(i,2,100004) {
        if (!is_prime[i]) continue;
        primes.pb(i);
        for (int k=2;k*i<100005;k++) is_prime[i*k]=false;
    }
    int ans=1e9+7;
    rep(i,n) {
        int cnt=0;
        rep(j,m){
            auto r = lower_bound(primes.begin(),primes.end(),a[i][j]);
            int k=r-primes.begin();
            cnt += primes[k]-a[i][j];
        }
        ans=min(ans,cnt);
    }
    rep(i,m) {
        int cnt=0;
        rep(j,n){
            auto r = lower_bound(primes.begin(),primes.end(),a[j][i]);
            int k=r-primes.begin();
            cnt += primes[k]-a[j][i];
        }
        ans=min(ans,cnt);
    }
    cout<<ans;
    return 0;
}