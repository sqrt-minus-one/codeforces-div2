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
const int N = 200010;
const int MOD = 1e9+7;
const ll INF = 1e18;
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int c[N][101];

int main() 
{ 
    setIO();
    int t; cin>>t;
    c[0][0] = 1;
    repL(i,1,N-1){
        c[i][0] = 1;
        repL(j,1,100){
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) %MOD;
        }
    }
    while (t--){
        int n,m,k; cin>>n>>m>>k;
        int a[n];
        read(a,n);
        sort(a,a+n);
        int i = 0; int j = 0;
        int ans = 0;
        while (1){
            while (j<n && a[j] - a[i] <= k){
                j++;
            }
            int l = j - i;
            if (l>= m) ans += c[l][m];
            
            ans %= MOD;
            if (j == n) break;
            while (i < n && a[j] - a[i] > k) i++;
            if (j - i >= m){
                l = j - i;
                ans -= c[l][m];
                ans = (MOD + ans)%MOD;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}