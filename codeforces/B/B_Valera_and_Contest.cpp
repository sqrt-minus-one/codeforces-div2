#include <iostream>
using namespace std;

int main() {
    int n,k,l,r,sa,sk;cin>>n>>k>>l>>r>>sa>>sk;
    int a[n+1];
    int sr=sa-sk;
    a[0]=r;
    for (int i=1;i<=k;i++){
        a[i]=a[i-1];
        while ((a[i]-1)*(k-i+1)>=sk) a[i]--; 
        sk-=a[i];
    }
    
    for (int i=k+1;i<=n;i++){
        a[i]=a[i-1];
        while ((a[i]-1)*(n-i+1)>=sr) a[i]--; 
        sr-=a[i];
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
    return 0;
}