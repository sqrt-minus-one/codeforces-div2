#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    int owe[n+1][n+1];
    memset(owe,0,sizeof(owe));
    for (int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        owe[a][b]=c;
    }

    for (int k=1;k<=n;k++){
        for (int a=1;a<=n;a++){
            for (int b=1;b<=n;b++){
                
                for (int c=1;c<=n;c++){
                    if (owe[a][c]!=0 && owe[c][b]!=0){
                        int m=min(owe[a][c],owe[c][b]);
                        owe[a][c]-=m;
                        owe[c][b]-=m;
                        owe[a][b]+=m;
                    }
                }
            }
        }
    }
    int ans=0;
    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++) ans+=owe[x][y];
    }
    cout<<ans;
    return 0;
}