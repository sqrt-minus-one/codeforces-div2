#include <bits/stdc++.h>
using namespace std;
int n,l,r,x;
int *c;
int solve(int i, int m,int M, int s){
    if (i>=n) {
        return (M-m>=x && s>=l && s<=r );
    }
    return solve(i+1,min(m,c[i]),max(M,c[i]),s+c[i])+solve(i+1,m,M,s);
}
int main() {
    cin>>n>>l>>r>>x;
    c = new int[n];
    for (int i=0; i<n; i++) cin>>c[i];
    int ans=0;
    cout<<solve(0,1e7,0,0);
    return 0;
}