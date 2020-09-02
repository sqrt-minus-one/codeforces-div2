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
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin>>n;
    string s; cin>>s;
    vector<int> v;
    int cnt=1;
    repL(i,1,n-1){
        if (s[i]==s[i-1]) cnt++;
        else {
            v.pb(cnt);
            cnt=1;
        }
    }
    v.pb(cnt);
    int ans = v.size();
    if (v[0]>2){
        cout<<ans+2;
        return 0;
    }
    cnt=0;
    rep(i,n){
        if (v[i]>2 ){
            cout<<ans+2;
            return 0;
        }
        if (v[i]==2) cnt++;
    }
    if (cnt>1) cout<<ans+2;
    else if (cnt==1) cout<<ans+1;
    else cout<<ans;
    return 0;
}