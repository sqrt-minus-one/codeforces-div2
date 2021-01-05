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
const int N = 110;
const int MOD = 1e9+7;
const ll INF = 1e18;
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int c[N];
ll p[N][N];
int n,m,k;
ll dp[N][N][N];
ll solve(int i, int last, int k_cnt){
    if (i == n){
        if (k_cnt != k) return INF;
        return 0;
    }
    if (dp[i][last][k_cnt] != -1) return dp[i][last][k_cnt];
    if (c[i] > 0){
        return dp[i][last][k_cnt] = solve(i+1, c[i], k_cnt + (c[i] != last));
    }
    ll ans = INF;
    repL(j,1,m){
        ans = min(ans, p[i][j] + solve(i+1, j , k_cnt + (j!=last)));
    }
    return dp[i][last][k_cnt] = ans;
}
int main() 
{ 
    setIO();
    cin>>n>>m>>k;
    read(c,n);
    rep(j,n) read1(p[j],m);
    rep(i,N) rep(j,N) rep(k, N) dp[i][j][k] = -1;
    ll ans = solve(0,0,0);

    cout<<((ans >= INF)? -1 : ans);
    return 0;
}