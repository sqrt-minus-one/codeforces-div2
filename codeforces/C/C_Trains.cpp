#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b; cin>>a>>b;
    if (a==b) {
        cout<<"Equal";
        return 0;
    }
    long long x=a*1ll*b/__gcd(a,b);
    long long m= (x/b)-1;
    long long d= (x/a)-1;
    if (a<b) m++;
    else d++;
    if (d<m) cout<<"Masha";
    else if (d>m) cout<<"Dasha";
    else cout<<"Equal";
    return 0;
}