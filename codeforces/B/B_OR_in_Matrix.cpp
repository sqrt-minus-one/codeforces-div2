#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    int B[n][m];
    int A[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>B[i][j];
            A[i][j]=B[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (B[i][j]==0){
                for (int k=0;k<m;k++) A[i][k]=0;
                for (int k=0;k<n;k++) A[k][j]=0;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (B[i][j]){
                bool valid=false;
                for (int k=0;k<m;k++) {
                    if (A[i][k]){
                        valid=true;
                        break;
                    }
                }
                if (valid) continue;
                for (int k=0;k<n;k++) {
                    if(A[k][j]) valid=1;
                }
                if (!valid) {
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cout<<A[i][j]<<' ';cout<<'\n';
    }
    return 0;
}