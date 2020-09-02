#include <iostream>
using namespace std;

int main() {
    int n,k;cin>>n>>k;
    int a[n];
    for (int i=0;i<n; i++) cin>>a[i];
    int sum=0;
    int cnt=0;
    for (int i=0;i<n;i++){
        if (a[i]<0) cnt++; 
    }
    if (cnt>=k){
        for (int i=0;i<n;i++){
            if (i<k) sum-=a[i];
            else sum+=a[i];
        }
        cout<<sum;
        return 0;
    }
    int m=abs(a[0]);
    for (int i=0;i<n;i++){
        sum+=abs(a[i]);
        m=min(m,abs(a[i]));
        a[i]*=-1;
    }
    k-=cnt;
    if (k%2==0) cout<<sum;
    else cout<<sum-2*m;
    return 0;
}