#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;
    string t; cin>>t;
    int ss[26*2];
    int tt[26*2];
    memset(ss,0,sizeof(ss));
    memset(tt,0,sizeof(tt));
    for (int i=0; i< s.length();i++){
        if (s[i]>='A' && s[i]<='Z'){
            ss[26+s[i]-'A']++;
        }
        else ss[s[i]-'a']++;
    }
    for (int i=0; i< t.length();i++){
        if (t[i]>='A' && t[i]<='Z'){
            tt[26+t[i]-'A']++;
        }
        else tt[t[i]-'a']++;
    }
    int yay=0;
    int whoops=0;
    for (int i=0;i<26*2;i++){
        if (ss[i]<=tt[i]){
            yay+=ss[i];
            tt[i]-=ss[i];
            ss[i]=0;
        }
        else {
            yay+=tt[i];
            ss[i]-=tt[i];
            tt[i]=0;
        }
    }
    for (int i=0;i<26;i++){
        whoops+=max(min(tt[i],ss[i+26]),min(tt[i+26],ss[i]));
    }
    cout<<yay<<' '<<whoops;
    return 0;
}