#include <iostream>
#include <vector>
#include <cstring>
#define N 110
using namespace std;
typedef pair<int,int> ii;
vector<ii> g[N];
bool vis[N][N];
bool dfs(int u,int v,int c){
    if (u==v) return true;
    if (vis[u][c]) return false;
    vis[u][c]=true;
    for (ii e : g[u]) if (e.second == c and dfs(e.first,v,c)) return true;
    return false;
}
int main() {
    int n,m;cin>>n>>m;
    for (int i=0;i<m;i++){
        int u,v,c; cin>>u>>v>>c;
        g[u].push_back(ii(v,c));
        g[v].push_back(ii(u,c));
    } 
    int q; cin>>q;
    for (int i=0;i<q;i++){
        int u,v; cin>>u>>v;
        int ans=0;
        memset(vis,false,sizeof(vis));
        for (int c=1;c<=m;c++){
            if (dfs(u,v,c)) ans++;
        }
            
        cout<<ans<<'\n';
    }
    return 0;
}