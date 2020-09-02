#include <bits/stdc++.h>
using namespace std;
int f(int limit,int n){
    return (limit-n)/(2*n)+1;
}
int main() {
    int sum,limit; cin>>sum>>limit;
    int k=log2(limit);
    vector<int> ans;
    while (k>=0){
        int cnt=0;
        int n=(1<<k);
        while (sum>=n && cnt<f(limit,n)){
            sum-= n;
            ans.push_back(n*(1+2*cnt));
            cnt++;
        }
        k--;
    }
    if (sum!=0) cout<<-1;
    else {
        cout<<ans.size()<<'\n';
        for (int c:ans) cout<<c<<' ';
    }
    return 0;
}