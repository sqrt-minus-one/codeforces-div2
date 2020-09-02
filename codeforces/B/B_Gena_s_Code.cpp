#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    string a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int num_zeros=0;
    int j=-1;
    for (int i=0;i<n;i++){
        if (a[i]=="0"){ 
            cout<<0; return 0;
        }
        string s=a[i];
        int k=s.length();
        bool valide=false;
        if (s[0]=='1'){
            valide=true;
            for (int j=1;j<k;j++){
                if (s[j]!='0'){
                    valide=false;
                    break;
                }
            }
        }
        if (valide)  num_zeros+=a[i].length()-1;
        else j=i;
    }
    if (j!=-1) cout<<a[j];
    else cout<<"1";
    for (int i=0;i<num_zeros;i++) cout<<'0';
    return 0;
}