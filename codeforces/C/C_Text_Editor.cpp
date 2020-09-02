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

int main() 
{ 
    /* freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); */
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin>>n;
    int a[n]; read(n,a);
    int r,c,rr,cc; cin>>r>>c>>rr>>cc; r--;rr--;c--;cc--;
    int m1[n],m2[n];
    m1[r]=c;
    repL(i,r+1,n) m1[i]=min(a[i]+1,m1[i-1]);
    repR(i,r-1,0) m1[i]=min(a[i]+1,m1[i+1]);
    m2[rr]=m1[rr];
    repL(i,rr+1,n) m2[i]=min(a[i],m2[i-1]);
    repR(i,rr-1,0) m2[i]=min(a[i],m2[i+1]);
    int ans= abs(r-rr) + abs(cc-m1[rr]); 
    if (c<=cc){
        cout<<ans;
        return 0;
    }
    rep(i,n){
        if (m1[i]==c) continue;
        ans = min(ans,abs(r-i) + abs(i-rr) + abs(cc-min(m1[i],m2[i])));
    }
    cout<<ans;
    return 0;
}