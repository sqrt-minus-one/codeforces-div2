#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b;cin>>a>>b;
    int x=0,y=0,z=0,xx=0,yy=0,zz=0;
    while (a>1 && a%2==0){
        a/=2; x++;
    }
    while (a>1 && a%3==0){
        a/=3; y++;
    }
    while (a>1 && a%5==0){
        a/=5; z++;
    }
    
    while (b>1 && b%2==0){
        b/=2; xx++;
    }
    while (b>1 && b%3==0){
        b/=3; yy++;
    }
    while (b>1 && b%5==0){
        b/=5; zz++;
    }
    if (a!=b) cout<<-1;
    else {
        cout<< abs(x-xx)+abs(y-yy)+abs(z-zz);
    }
    return 0;
}