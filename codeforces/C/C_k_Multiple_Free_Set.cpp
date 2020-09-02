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
    int n,k; cin>>n>>k;
    vector<ll> a(n);
    read(n,a);
    sort(a.begin(),a.end());
    if (k==1){
        int cnt=0;
        rep(i,n){
            cnt++; i++;
            while (i<n && a[i]==a[i-1]) i++; i--;
        }
        cout<<cnt; 
        return 0;
        
    }
    int prev[n];
    int next[n];
    rep(i,n) prev[i]=-1;
    rep(i,n) next[i]=-1;
    rep(i,n){
        ll x=a[i];
        ll y = x*k;
        auto j = lower_bound(a.begin(),a.end(),y);
        if (j!=a.end() && y==*j) next[i]=j-a.begin();
        if (x%k) continue;
        y = x/k;
        j = lower_bound(a.begin(),a.end(),y);
        if (j!=a.end() && y==*j) prev[i]=j-a.begin();
    }
    int ans=0;
    rep(i,n){
        if (prev[i] != -1) continue;
        int cnt = 1;
        int x=i;
        while (next[x] != -1){
            x=next[x];
            cnt++;
        }
        if (cnt&1) ans+= (cnt+1)>>1;
        else ans+= cnt>>1; 
    }
    cout<<ans;
    return 0;
}