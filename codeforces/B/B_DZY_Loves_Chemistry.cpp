#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define N 55
using namespace std;
bool vis[N];
vector<int> g[N];
void dfs(int u){
    if (vis[u]) return;
    vis[u]=1;
    for (int v:g[u]) dfs(v);
}
int main() {
    int n,m; cin>>n>>m;
    memset(vis,false,sizeof(vis));
    for (int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cc=0;
    for (int i=1;i<=n;i++){
        if (!vis[i]) {
            cc++;
            dfs(i);
        }
    }
    long long ans=1;
    for (int i=0;i<n-cc;i++) ans*=2;
    cout<<ans;
    return 0;
}