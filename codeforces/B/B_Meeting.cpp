#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef struct circle circle;
struct circle{
    int x,y,r;
};
int main() {
    int xa,xb,ya,yb; cin>>xa>>ya>>xb>>yb;
    vector<ii> points;
    for (int i=min(ya,yb);i<=max(ya,yb);i++){
        points.push_back(ii(xa,i));
        points.push_back(ii(xb,i));
    }
    for (int i=min(xa,xb)+1;i<max(xa,xb);i++){
        points.push_back(ii(i,ya));
        points.push_back(ii(i,yb));
    }
    int n; cin>>n;
    vector<circle> circles;
    for (int i=0;i<n;i++){
        int x,y,r;cin>>x>>y>>r;
        circles.push_back({x,y,r});
    }
    int ans=0;
    for (auto p:points){
        bool key=true;
        for (auto c : circles){
            int x,y,r; x=c.x;y=c.y;r=c.r;
            int a,b; a=p.first; b=p.second;
            if ((x-a)*(x-a)+(y-b)*(y-b)<=r*r) {
                key=false;
                break;
            }
        }
        if (key) ans++;
    }
    cout<<ans;
    return 0;
}