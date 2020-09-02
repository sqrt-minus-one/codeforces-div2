#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b; cin>>a>>b;
    int n=a.length();
    int m=b.length();
    int t[m+1],s[n+1];
    for (int i=0;i<n;i++) s[i+1]= a[i]-'0';
    for (int i=0;i<m;i++) t[i+1]= b[i]-'0';
    int p[m+1]; p[0]=0;
    for (int i=1;i<=m;i++){
        p[i]=t[i]+p[i-1];
    }
    long long ans=0;
    for (int i=1;i<=n;i++){
        int x=p[m-n+i]-p[i-1];
        if (s[i]==0) ans+=x*1ll;
        else ans+=(m-n-x+1)*1ll;
    }
    cout<<ans;
    return 0;
}