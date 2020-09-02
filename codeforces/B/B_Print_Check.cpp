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
    int n,m,k; cin>>n>>m>>k;
    pi columns[m+1],rows[n+1];
    rep(i,m+1) {
        columns[i] = {-1,0};
    }
    rep(i,n+1) rows[i] = {-1,0};
    rep(i,k){
        int x,r,c; cin>>x>>r>>c;
        if (x==1) rows[r] = {i,c};
        else columns[r] = {i,c};
    }
    repL(i,1,n) {
        repL(j,1,m) {
            if (columns[j].F<rows[i].F) cout<<rows[i].S;
            else cout<<columns[j].S;
            cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}