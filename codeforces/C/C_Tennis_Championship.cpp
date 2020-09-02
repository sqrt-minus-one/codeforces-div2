#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define all(c) c.begin(),c.end()
#define endl '\n'
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
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

struct Matrix{
    ll[2][2] mat;
};

ll[][] mult(ll[][] a,ll[][] b){
    int n=sizeof(a)/sizeof(a[0]);
    ll[n][n] ans; memset(ans,0,sizeof(ans));
    rep(i,n){
        rep(j,n){
            rep(k,n){
                ans[i][j]+=ans[i][k]*ans[k][j];
            }
        }
    }
    return ans;
}

ll[][] power(ll[][] base,int p){
    int n=sizeof(base)/sizeof(base[0]);
    ll ans[n][n]; rep(i,n) rep(j,n) ans[i][j]= (i==j);
    while (p){
        if (p^1) ans=mult(ans,base);
        base = mult(base,base);
        p>>=1;
    }
    return ans;
}

ll fib(int n){
    ll a[2][2] = P={{1,1},{1,0}};
    a = power(a,n-1);
    return 2*a[0][0]+a[0][1];
}



int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0);
    return 0;
}