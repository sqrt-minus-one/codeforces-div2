#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> num;
    for (int i=0;i<n;i++){
        char c; cin>>c;
        if (c=='1' || c=='0') continue;
        if (c=='4') {
            num.push_back(2);
            num.push_back(2);
            num.push_back(3);
        }
        else if (c=='6') {
            num.push_back(5);
            num.push_back(3);
        }
        else if (c=='8'){
            num.push_back(2);
            num.push_back(2);
            num.push_back(2);
            num.push_back(7);
        }
        else if (c=='9'){
            num.push_back(7);
            num.push_back(2);
            num.push_back(3);
            num.push_back(3);
        }
        else num.push_back(c-'0');
    }
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    for (int i:num) cout<<i;
    return 0;
}