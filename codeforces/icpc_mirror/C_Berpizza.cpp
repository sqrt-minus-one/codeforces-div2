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
const int N = 500010;
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
    int q;cin>>q;
    int m[N];

    priority_queue<pi> pq;
    priority_queue<int> customers;
    
    int i = 1;
    vi ans;
    while (q--){
        int t; cin>>t;
        int c;

        switch(t){
            case 1: {
                cin>>m[i]; pq.push({m[i], -i}); customers.push(-i); i++; break;
            }
            case 2: {
                while (true){
                    c = -customers.top(); customers.pop();
                    if (m[c]>0){
                        ans.pb(c);
                        m[c] *= -1;
                        break;
                    }
                }
                break;
            }
            case 3: {
                while (true){
                    c = -pq.top().second; pq.pop();
                    if (m[c] > 0){
                        ans.pb(c);
                        m[c] *= -1;
                        break;
                    }
                }
                break;
            }
        }
    }
    write(ans,sz(ans),' ');
    return 0;
}