#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;cin>>n>>a>>b;
    for (int i=0;i<n;i++){
        long long x; cin>>x;
        cout<<((x*1ll*a)%b)/a<<' ';
    }
    return 0;
}