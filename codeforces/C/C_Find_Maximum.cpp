#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define M 1e9 + 7
#define mod(n) if (n>=M) n-=M;
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
#define write(n,a,s) rep(i,n) cout<<a[i]<<s;cout<<endl

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n;cin>>n;
    int a[n+1];
    repL(i,1,n) cin>>a[i];
    int p[n+1];
    int m[n+1];
    repL(i,1,n) {
        char c; cin>>c;
        m[i]=c-'0';
    }
    memset(p,0,sizeof(p));
    repL(i,1,n+1){
        p[i]=a[i]+p[i-1];
    }
    int ans=0;
    int r=0;
    repR(i,n,1){
        if (m[i]){
            ans=max(ans,r+p[i-1]);
            r+=a[i];
        }
    }
    ans=max(ans,r);
    cout<<ans;
    return 0;
}