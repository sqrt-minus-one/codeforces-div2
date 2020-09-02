#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin>>n>>k;
    int a[n];
    for (int i=0; i<n;i ++) cin>>a[i];
    vector<pair<int,int>> ans;
    for (int i=0; i<k; i++){
        int m=a[0],M=a[0];
        int x=0,y=0;
        for (int j=0; j<n;j++){
            if (a[j]>M){
                M=a[j]; x=j;
            }
            if (a[j]<m){
                m=a[j]; y=j;
            }
        }
        if (M-m <= 1) break;
        ans.push_back({x+1,y+1});
        a[x]--; a[y]++;
    }
    int m=a[0],M=a[0];
    for (int i=0;i<n;i++){
        if (a[i]>M) M=a[i];
        if (a[i]<m) m=a[i];
    }
    cout<<M-m<<' '<<ans.size()<<'\n';
    for (auto r : ans) cout<<r.first << ' ' << r.second <<'\n';
    return 0;
}