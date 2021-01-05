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
bool between(int x, int a, int b){
    return (min(a,b) <= x && x <= max(a,b));
}
int main() 
{ 
    setIO();
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        int pos = 0;
        int curr_pos = 0;
        int dest_pos = 0;
        pair<ll,int> commands[n+1];
        rep(i,n) cin>>commands[i].F>>commands[i].S;
        commands[n] = {1e18,0};
        int ans = 0;
        rep(i,n){
            int t = commands[i].F, x = commands[i].S;
            int t_next = commands[i+1].F;
            int dt = abs(t_next - t);
            if (curr_pos == dest_pos){
                dest_pos = x;
            }
            int distance = abs(dest_pos - curr_pos);
            if (distance <= dt ){
                if (between(x,curr_pos,dest_pos)) {
                    ans++;
                }
                curr_pos = dest_pos;
            }
            else {
                distance = abs(x - curr_pos);
                if (distance <= dt && between(x,curr_pos,dest_pos)) ans++;
                if (curr_pos < dest_pos) curr_pos += dt;
                else curr_pos -= dt;
            }
        
        }
        cout<<ans<<endl;
    }   
    return 0;
}