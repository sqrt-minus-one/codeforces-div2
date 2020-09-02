#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n=s.length();
    bool ch[26];
    for (int i=0;i<n-25;i++){
        bool nice=true;
        memset(ch,false,sizeof(ch));
        for (int j=0;j<26 ;j++){
            if (s[i+j]=='?') continue;
            if (ch[s[i+j]-'A']) {
                nice=false;
                break;
            }
            else ch[s[i+j]-'A']=true;
        }
        if (nice){
            int k=0;
            for (int j=0;j<26;j++){
                if (ch[j]) continue;
                for (;k<26;k++){
                    if (s[i+k]=='?') {
                        s[i+k]='A'+j;
                        break;
                    }
                }
            }
            for(int j=0;j<n;j++) if(s[j]=='?')s[j]='A';
            cout<<s;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}