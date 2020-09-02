#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int max_int[n];
    int max_const_int[n];
    max_int[0]=1;
    max_const_int[0]=1;
    int ans=1;
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]){
            max_int[i]=max_int[i-1]+1;
            max_const_int[i]=max_const_int[i-1]+1;
        }
        else if (abs(a[i]-a[i-1])<=1){
            if (max_int[i-1]==max_const_int[i-1] || a[i]==a[i-1-max_const_int[i-1]]){
                max_int[i]=max_int[i-1]+1;
                max_const_int[i]=1;
            }
            else {
                max_int[i]=max_const_int[i-1]+1;
                max_const_int[i]=1;
            }
        }
        else {
            max_int[i]=1;
            max_const_int[i]=1;
        }
        ans=max(ans,max_int[i]);
    }
    cout<<ans;
    return 0;
}