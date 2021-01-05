#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define mod 1e9 + 7
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define repL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define repR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define trav(x,a) for (auto& x: a)
using ll = long long int; 
using vi = vector<int>;
using pi = pair<int, int>;
#define F first
#define S second
#define pb push_back 
#define pob pop_back
#define read(a,n) rep(i,n) cin>>a[i]
#define write(a,n,s) rep(i,n) cout<<a[i]<<s;
const int N = 100010;
const int MOD = 1e9+7;
const ll INF = 1e18;
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
struct info{
    string num;
    int bulls;
    int cows;
};
bool valid(string s){
    set<char> c;
    trav(x,s) c.insert(x);
    return c.size() == s.length();
}
bool test(string s, info d){
    int bulls = 0;
    rep(i,s.length()){
        if (s[i] == d.num[i]) bulls++;
    }
    if (bulls != d.bulls) return false;
    int cows = 0;
    rep(i,s.length()){
        if (d.num[i] != s[i]){
            rep(j,s.length()){
                if (d.num[i] == s[j]){
                    cows++;
                    break;
                }
            }
        }
    }
    return cows == d.cows;
}
int main() 
{ 
    setIO();
    int n; cin>>n;
    info a[n];
    rep(i,n) cin>>a[i].num>>a[i].bulls>>a[i].cows;
    string ans = "";
    repL(i,101,9876){
        string s = to_string(i);
        if (s.length() < 4) s = "0"+s;
        if (valid(s)){
            bool ok = true;
            rep(k,n){
                ok &= test(s,a[k]);
            }
            if (ok){
                if (ans == "") ans = s;
                else {
                    cout<<"Need more data";
                    return 0;
                }
            }
        }
    }
    if (ans == "") cout<<"Incorrect data";
    else cout<< ((ans.length()<4)? "0":"")<<ans;
    return 0;
}