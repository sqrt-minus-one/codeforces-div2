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
#define write(a,n,s) repL(i,1,n) cout<<a[i]<<s;
const int N = 100010;
const int MOD = 1e9+7;
const ll INF = 1e18;
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin);
        //freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() 
{ 
    setIO();
    int t; cin>>t;
    while (t--){
        int n; cin>>n;

        map<int,set<int>> persons;
        map<pi,set<int>> pos;

        rep(i,n){
            int h,w; cin>>h>>w;
            persons[h].insert(w);
            persons[w].insert(h);
            
            pos[{h,w}].insert(i+1);
            pos[{w,h}].insert(i+1);
        }
        int ans[n+1];
        repL(i,1,n) ans[i] = -1;
        trav(x,persons){
            int h=x.F;
            trav(w, x.S){
                int i =*pos[{h,w}].begin();
                if (ans[i] != -1) continue;
                auto p = persons.upper_bound(x.F);
                for (;p != persons.end(); p++){
                    auto y = upper_bound(all(p->S), w);
                    if (y == p->S.end()) continue;

                    int hh = p->F, ww = *y;
                    int j = *pos[{hh,ww}].begin();
                    vi removed;
                    for (; y != p->S.end(); y++){
                        ww = *y;
                        removed.pb(ww);
                        for (auto k : pos[{hh,ww}]){
                            ans[k] = i;
                        }
                    }
                    trav(r, removed) p->S.erase(r);
                }
            }
        }
        write(ans,n,' ');cout<<endl;
    }
    return 0;
}