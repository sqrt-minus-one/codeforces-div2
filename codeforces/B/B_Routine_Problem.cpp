#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    int a,b,c,d; cin>>a>>b>>c>>d;
    int dd,x,y;
    if (b*c>a*d){
        y=b*c;
        x=b*c-a*d;
        dd=__gcd(x,y);
        
    }
    else {
        x=a*d-b*c;
        y=a*d;
        dd=__gcd(x,y);
    }
    cout<<x/dd<<'/'<<y/dd;
    return 0;
}