#include <bits/stdc++.h>
using namespace std;
#define N 1010
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
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin>>n;
    int a[n]; rep(i,n) cin>>a[i];
    int m = a[0];
    rep(i,n) m = min(m,a[i]);
    int extra = 0;
    int cnt=0;
    rep(i,n){
        if (a[i]==m){
            extra=max(extra,cnt);
            cnt=0;
        }
        else cnt++;
    }
    rep(i,n){
        if (a[i]==m) break;
        cnt++;
    }
    extra = max(extra,cnt);
    cout<< n*1ll*m + extra;
    return 0;
}