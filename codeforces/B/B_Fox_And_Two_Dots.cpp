#include <bits/stdc++.h>
using namespace std;
char field[51][51];
int n,m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[51][51];
void solve(int i,int j,int x,int y, char c){
    if (i<0 ||i>=n || j<0 || j>=m || field[i][j]!=c) return ;
    if (vis[i][j]){
        cout<<"Yes\n"; exit(0);
    }
    vis[i][j]=1;
    for (int k=0;k<4;k++){
        int ii=i+dx[k],jj=j+dy[k];
        if (ii==x && jj==y) continue;
        solve(ii,jj,i,j,c);
    }
    vis[i][j]=1;

}
int main() {
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>field[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!vis[i][j]) solve(i,j,-1,-1,field[i][j]);
        }
    }
    cout<<"No";
    return 0;
}