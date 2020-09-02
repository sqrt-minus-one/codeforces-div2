#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
int main() {
    int n; cin>>n;
    vector<ii> a;
    for (int i=0; i<n;i++){
        int x;cin>>x;
        a.push_back(ii(x,i));
    }
    a.push_back(ii(100001,100001));
    sort(a.begin(),a.end());
    int cnt=0;
    vector<ii> ans;
    bool valide=true;
    int p=0;
    for (int i=1;i<=n;i++){
        if (a[i].first!=a[i-1].first){
            if (valide) ans.push_back(ii(a[i-1].first,p));
            valide =1;
            p=0;
        }
        else{
            if (p==0) p=a[i].second-a[i-1].second;
            else if (p!=a[i].second-a[i-1].second) valide =0;
        }
    }
    cout<<ans.size()<<'\n';
    for (auto x :ans) cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}