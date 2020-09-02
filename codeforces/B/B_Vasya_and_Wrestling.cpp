#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> f,s;
    long long s1=0,s2=0;
    string last;
    for (int i=0;i<n;i++){
        int a; cin>>a;
        if (a>0){
            f.push_back(abs(a));
            s1+=a;
            last="first";
        }
        else {
            s2-=a;
            s.push_back(abs(a));
            last="second";
        }
    }
    if (s1>s2) cout<<"first";
    else if (s1<s2) cout<<"second";
    else {
        int i=0;
        int x=f.size();
        int y=s.size();
        while (i<x && i<y && s[i]==f[i]) i++;
        if (i==x && x==y) cout<<last;
        else {
            if (i==x) cout<<"second";
            else if (i==y) cout<<"first";
            else if (f[i]>s[i]) cout<<"first";
            else cout<<"second";
        }
    }
    return 0;
}