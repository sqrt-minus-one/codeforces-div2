#include <bits/stdc++.h>
using namespace std;
vector<int> *g;
typedef pair<int,int> ii;
bool *vis;
ii dfs(int u){
    if (vis[u]) return ii(0,0);
    vis[u]=1;
    int ans=g[u].size();
    int cnt=1;
    for (int v : g[u]){
        ii r=dfs(v);
        cnt+=r.first;
        ans+=r.second;
    }
    return ii(cnt,ans);
}

int main() {
    int n, m;cin>>n>>m;
    g=new vector<int>[n+1];
    vis=new bool[n+1];
    memset(vis,true,sizeof(vis));
    for (int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        vis[a]=false;
        vis[b]=false;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            ii r = dfs(i);
            int x=r.first;
            int y=r.second;
            if ((long long )x*(x-1) != y) {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}