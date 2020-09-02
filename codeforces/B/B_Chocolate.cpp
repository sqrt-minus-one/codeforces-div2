#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int i=0;
    for (;i<n && !a[i];i++);
    if (i==n) {
        cout<<0;
        return 0;
    }
    long long ans=1;
    for (int j=i+1;j<n;j++){
        if (a[j]==1){
            ans*=(j-i);
            i=j;
        }
    }
    cout<<ans;
    return 0;
}