#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    int count[5001];
    memset(count,0,sizeof(count));
    for (int i=0;i<n;i++){
        int c; cin>>c;
        count[c]++;
    }
    int ans=n;
    for (int m=1;m<=5000;m++){
        if (count[m]!=0){
            int r=0;
            for (int i=1;i<m;i++)r+=count[i];
            for (int i=2*m+1;i<=5000;i++) r+=count[i];
            ans=min(ans,r);
        }
    }
    cout<<ans;
    return 0;
}