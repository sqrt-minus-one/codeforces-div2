#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double vp,vd,t,f,c;cin>>vp>>vd>>t>>f>>c;
    if (vd<=vp) {
        cout<<0;
        return 0;
    }
    int cnt=0;
    while (vp*t<c){
        double td=vp*1.0*t/(vd-vp);
        t+=td;
        if (t*vp>=c) break;
        else {
            cnt++;
            t+=td+f;
        }
    }
    cout<<cnt;
    return 0;
}