#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    int g[1001][1001];
    memset(g,0,sizeof(g));
    for (int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        g[x][y]++;
    }
    long long ans=0;
    for (int i=1;i<=1000;i++){
        int cnt=0;
        for (int j=0;i-j>0 && j<1000;j++){
            cnt+=g[i-j][j+1];
        }
        ans+= cnt*1ll*(cnt-1)/2;
        cnt=0;
        for (int j=0;i+j<=1000 && j<1000;j++){
            cnt+=g[i+j][j+1];
        }
        ans+= cnt*1ll*(cnt-1)/2;
    }
    for (int j=2;j<=1000;j++){
        int cnt=0;
        for (int i=1;i<=1000 && i+j-1<=1000;i++) cnt+=g[i][j+i-1];
        ans+= cnt*1ll*(cnt-1)/2;
    }
    for (int j=2;j<=1000;j++){
        int i=1000;
        int cnt=0;
        for (int k=0;i-k>0 && j+k<=1000;k++) cnt+=g[i-k][j+k];
        ans+= cnt*1ll*(cnt-1)/2;
    }
    cout<<ans;
    return 0;
}