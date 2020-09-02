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
    int n,m,k; cin>>n>>m>>k;
    int t[n+1][m+1];
    rep(i,n) rep(j,m) cin>>t[i+1][j+1];
    int rows[n+1],columns[m+1];
    rep(i,n+1) rows[i]=i;
    rep(j,m+1) columns[j]=j;
    while (k--){
        char s; int x,y; cin>>s>>x>>y;
        if (s=='g') cout<<t[rows[x]][columns[y]]<<endl;
        else if (s=='c') swap(columns[x],columns[y]);
        else swap(rows[x],rows[y]);
    }     
    return 0;
}