#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    string rec; cin>>rec;
    ll nb,ns,nc; cin>>nb>>ns>>nc;
    ll pb,ps,pc; cin>>pb>>ps>>pc;
    ll r; cin>>r;
    ll b=0,s=0,c=0;
    for (char re:rec){
        if (re=='B') b++;
        else if (re=='C') c++;
        else s++;
    }
    ll x=0,y=1e13;
    ll k;
    while (x<y){
        k=((x+y)>>1);
        if (pb*max(b*k-nb,0ll)+ps*max(s*k-ns,0ll)+pc*max(c*k-nc,0ll)>r) y=k;
        else {
            x=k+1;
        }
    }
    cout<<x-1;
    return 0;
}