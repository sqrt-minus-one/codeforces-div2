#include <bits/stdc++.h>
using namespace std;
string n;
int k;
vector<int> luckies;

void gen_luckies(int i,string r){
    if (i==k){
        luckies.push_back(stoi(r));return;
    }
    gen_luckies(i+1,r+'4');
    gen_luckies(i+1,r+'7');
}

int main() {
    cin>>n;
    k=n.length();
    gen_luckies(0,"");
    sort(luckies.begin(),luckies.end());
    int ans;
    if (k==1) ans=0;
    else ans= (1<<k)-2;
    for (int i=0;i<luckies.size() && luckies[i]<=stoi(n);i++){
        ans++;
    }
    cout<<ans;
    return 0;
}