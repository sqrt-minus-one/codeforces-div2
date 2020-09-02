#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main() {
    int n,d; cin>>n>>d;
    vector<ii> frds;
    for (int i=0;i<n;i++){
        int m,s;cin>>m>>s;
        frds.push_back(ii(m,s));
    }
    sort(frds.begin(),frds.end());
    int i=0,j=0;
    long long ans=0;
    long long tmp=0;
    for (;i<n;i++){
        while (j<n && (frds[j].first-frds[i].first)<d) {
            tmp+=1ll*frds[j].second;
            j++;
        }
        ans=max(ans,tmp);
        if (j==n) break;
        tmp-=1ll*frds[i].second;
    }
    cout<<ans;
    return 0;
}