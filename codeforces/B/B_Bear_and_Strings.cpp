#include <iostream>
using namespace std;

int main() {
    string s;cin>>s;
    string p="bear";
    int n=s.length();
    int m=p.length();
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=i+3;j<n;j++){
            int r=0;
            for (;r<=3 && p[r]==s[j-3+r];r++);
            if (r==4){
                ans+=n-j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}