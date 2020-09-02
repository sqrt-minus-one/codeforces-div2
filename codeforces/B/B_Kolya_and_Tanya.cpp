#include <iostream>
using namespace std;
const int mod=1e9+7;
int main() {
    int n; cin>>n;
    long long x=1,y=1;
    for (int i=0;i<n;i++){
        x=(((((x*3)%mod)*3)%mod)*3)%mod;
        y=(y*7)%mod;
    }
    cout<<(x-y+mod)%mod;
    return 0;
}