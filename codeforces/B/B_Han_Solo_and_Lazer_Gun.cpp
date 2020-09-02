#include <iostream>
using namespace std;
typedef pair<int,int> ii;

int main() {
    int n,x0,y0; cin>>n>>x0>>y0;
    ii points[n];
    bool alive[n];
    for (int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second; alive[i]=true;
    }
    int ans=0;
    for (int i=0;i<n;i++){
        if (alive[i]){
            alive[i]=false;
            ans++;
            int x,y; x=points[i].first; y=points[i].second;
            for (int j=0;j<n;j++) {
                if (alive[j]){
                    int a,b; a=points[j].first; b=points[j].second;
                    if ((x0-x)*(y0-b)==(x0-a)*(y0-y)) alive[j]=false;
                }
            } 
        }
    }
    cout<<ans;
    return 0;
}