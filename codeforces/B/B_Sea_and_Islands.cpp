#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n,k; cin>>n>>k;
    if (2*(k-1)>=n*n) {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if ((i+j)%2==0 && k>0) {
                cout<<'L';
                k--;
            }
            else cout<<'S';
        }
        cout<<'\n';
    }
    return 0;
}