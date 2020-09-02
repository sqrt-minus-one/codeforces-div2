#include <iostream>
#include <algorithm>
using namespace std;

bool inc(string s,string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    int i=0;
    for (int j=0;j<s.length()&&i<t.length();j++){
        if (s[j]==t[i])i++;
    }
    return i==t.length();
}

bool same_ord(string s,string t){
    int i=0;
    for (int j=0;j<s.length()&&i<t.length();j++){
        if (s[j]==t[i])i++;
    }
    return i==t.length();
}

int main() {
    string s,t; cin>>s>>t;
    if(s.length()<t.length()){
        cout<<"need tree";
        return 0;
    }
    if (s.length()==t.length()){
        if (inc(s,t)) cout<<"array";
        else cout<<"need tree";
    }
    else{
        if (inc(s,t)){
            if (same_ord(s,t)) cout<<"automaton";
            else cout<<"both";
        }
        else cout<<"need tree";
    }
    return 0;
}