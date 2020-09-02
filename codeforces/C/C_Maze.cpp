#include <bits/stdc++.h>
using namespace std;
#define N 550
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
char grid[N][N];
bool vis[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m,k;
void solve(int i,int j){
    if (i<0 || j<0 || i>=n || j>=m || grid[i][j]!='.' || vis[i][j]) return;
    vis[i][j]=true;
    rep(r,4){
        solve(i+dx[r],j+dy[r]);
    }
    if (k>0) {
        grid[i][j]='X';
        k--;
    }
}
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin>>n>>m>>k;
    rep(i,n) rep(j,m) cin>>grid[i][j];
    memset(vis,false,sizeof(vis));
    rep(i,n) rep(j,m) if (grid[i][j]=='.') {
        solve(i,j);
        break;
    }
    rep(i,n) {rep(j,m)cout<<grid[i][j]; cout<<endl;}
    return 0;
}