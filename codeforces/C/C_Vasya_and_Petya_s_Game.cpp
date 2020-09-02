#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    bool primes[n+1]; memset(primes,true,sizeof(primes));
    for (int i=2;i<=n;i++){
        if (!primes[i]) continue;
        for (int j=2; j*i<=n;j++) primes[i*j] = false;
    }
    vector<int> ans;
    for (int i=2; i<=n;i++){
        if (!primes[i]) continue;
        int k=i;
        while (k<=n){
            ans.push_back(k);
            k*=i;
        }
    }
    cout<<ans.size()<<'\n';
    for (int r : ans) cout<<r<<' ';
    return 0;
}