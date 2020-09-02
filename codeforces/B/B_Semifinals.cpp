#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int T1[n+2],T2[n+2];
    for (int i=1;i<=n;i++) cin>>T1[i]>>T2[i];
    T1[0]=0; T2[0]=0;
    T1[n+1]=1e9+5;T2[n+1]=1e9+5;
    if (n==1){
        cout<<(T1[1]<T2[1])<<"\n"<<(T2[1]<T1[1]);
        return 0;
    }
    int ans1=0,ans2=0;
    for (int k=0; 2*k<=n;k++){
        int a=k+1,b=n+1;
        while (a<b){
            int m=(a+b)>>1;
            int x=T1[m];
            int aa=k+1,bb=n+1;
            while (aa<bb){
                int i=(aa+bb)>>1;
                int xx=T2[i];
                if (xx>x) bb=i;
                else aa=i+1;
            }
            bb--;
            if (m+bb>n) b=m;
            else a=m+1;
        }
        ans1=max(ans1,b);
        a=k+1,b=n+1;
        while (a<b){
            int m=(a+b)>>1;
            int x=T2[m];
            int aa=k+1,bb=n+1;
            while (aa<bb){
                int i=(aa+bb)>>1;
                int xx=T1[i];
                if (xx>x) bb=i;
                else aa=i+1;
            }
            bb--;
            if (m+bb>n) b=m;
            else a=m+1;
        }
        ans2=max(ans2,b);
    }
    for (int i=1;i<=n;i++) cout<< (i<ans1);cout<<'\n';
    for (int i=1;i<=n;i++) cout<< (i<ans2);cout<<'\n';
    return 0;
}