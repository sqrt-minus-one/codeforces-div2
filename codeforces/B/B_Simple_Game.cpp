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
    if (n==1){
        cout<<1; return 0;
    }
    if (n%2) {
        if (m>=(n+1)/2) cout<<m-1;
        else cout<<m+1;
    }
    else {
        if (m<=n/2) cout<<m+1;
        else cout<<m-1;
    }
    return 0;
}