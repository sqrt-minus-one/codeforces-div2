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
#define read1(a,n) repL(i,1,n) cin>>a[i]
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

int main() 
{ 
    setIO();
    int t; cin>>t;
    while (t--){
        string s; cin>>s;
        int u = 0, d = 0, l =0, r = 0;
        trav(c, s){
            if (c=='U')u++;
            if (c == 'D')d++;
            if (c == 'L')l++;
            if (c == 'R') r++;
        }
        if ((l==r && u == d) || (abs(l-r) >= 1 && abs(u - d) >= 1)) cout<<"0 0\n";
        else {
            if (abs(l-r) >= 1){
                int x = 0, y = 0;
                char target;
                int cnt = 0;
                if (l < r) target = 'R';
                else target = 'L';

                trav(c,s){
                    if (c == 'L'){
                        x--;
                        if (target == c){
                            cnt++;
                            if (cnt == r+1) {
                                cout<<x<<' '<<y<<endl;
                                break;
                            }
                        }
                    }
                    else if (c == 'R'){
                        x++;
                        if (target == c){
                            cnt++;
                            if (cnt == l+1) {
                                cout<<x<<' '<<y<<endl;
                                break;
                            }
                        }
                    }
                    else if (c == 'U') y++;
                    else if (c == 'D') y--;
                }
            }
            else {
                int x = 0, y = 0;
                char target;
                int cnt = 0;
                if (u < d) target = 'D';
                else target = 'U';
                trav(c,s){
                    if (c == 'U'){
                        y++;
                        if (target == c){
                            cnt++;
                            if (cnt == d + 1) {
                                cout<<x<<' '<<y<<endl;
                                break;
                            }
                        }
                    }
                    else if (c == 'D'){
                        y--;
                        if (target == c){
                            cnt++;
                            if (cnt == u + 1) {
                                cout<<x<<' '<<y<<endl;
                                break;
                            }
                        }
                    }
                    else if (c == 'L') x--;
                    else if (c == 'R') x++;
                }
            }
        }
    }
    return 0;
}