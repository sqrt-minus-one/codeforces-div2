#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> pll;
int main() {
    int n; cin>>n;
    int k;
    long long x=0,y=0;
    int lx=0,ly=0;
    cin>>k;
    for (int i=0;i<k;i++){
        long long c; cin>>c;
        bool is_ten=false;
        if (c==10) is_ten=1;
        c*=pow(10ll,lx*1ll);
        lx+=is_ten;
        x+=c;
        lx++;
    }
    cin>>k;
    for (int i=0;i<k;i++){
        long long c; cin>>c;
        bool is_ten=false;
        if (c==10) is_ten=1;
        c*=pow(10ll,ly*1ll);
        ly+=is_ten;
        y+=c;
        ly++;
    }
    set<pll> mem;
    mem.insert(pll(x,y));
    int cnt=0;
    while (x && y){
        int xx,yy;
        xx=x%10;
        yy=y%10;
        if (xx==0){
            xx=10;
            x/=10;
            lx--;
        }
        if (yy==0){
            yy=10;
            y/=10;
            ly--;
        }
        x/=10;
        y/=10;
        lx--;ly--;
        if (xx<yy){
            y+=(yy*10+xx)*1ll*pow(10,ly);
            ly+=2;
            if (yy==10) ly++;
        }else {
            x+=(xx*10+yy)*1ll*pow(10,lx);
            lx+=2;
            if (xx==10) lx++;
        }
        if (mem.count(pll(x,y))) {
            cout<<"-1";
            return 0;
        }
        cnt++;
        mem.insert(pll(x,y));
    }
    cout<<cnt<<' ';
    if (x) cout<<1; 
    else cout<<2;
    return 0;
}