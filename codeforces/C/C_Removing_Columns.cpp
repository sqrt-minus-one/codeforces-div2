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
    int n,m; cin>>n>>m;
    string words[n];
    rep(i,n) cin>>words[i];
    bool removed[m];
    memset(removed,false,sizeof(removed));
w:
    rep(i,n-1){
        rep(j,m){
            if (removed[j]) continue;
            if (words[i][j]>words[i+1][j]) {
                removed[j]=true; 
                goto w;
            }
            if (words[i][j]<words[i+1][j]) break;
        }
    }
    int cnt=0;
    rep(i,m) cnt+=removed[i];
    cout<<cnt;
    return 0;
}