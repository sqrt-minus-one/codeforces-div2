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
        //freopen((name+".out").c_str(), "w", stdout);
    }
}
pi solve1(vector<pi>& line){
    sort(all(line));
    int n = sz(line);
    pi r = {-1,-1};
    if (n % 2)  r = line[n-1];
    rep(i,n/2) cout<<line[2*i].S<<' '<<line[2*i+1].S<<endl;
    return r;
}
pi solve2(vector<pair<pi,int>>& plan){
    map<int,vector<pi>> pplan;
    vector<pi> line;
    trav(x,plan){
        pplan[x.F.S].pb({x.F.F,x.S});
    }
    trav(x,pplan){
        auto r = solve1(x.S);
        if (r.S != -1){
            line.pb({x.F,r.S});
        }
    }
    return solve1(line);
}
void solve3(map<int,vector<pair<pi,int>>>& space){
    vector<pi> line;
    trav(x,space){
        auto r = solve2(x.S);
        if (r.S != -1){
            line.pb({x.F,r.S});
        }
    }
    solve1(line);
}
int main() 
{ 
    setIO();
    int n; cin>>n;
    map<int,vector<pair<pi,int>>> points;
    rep(i,n){
        int x,y,z; cin>>x>>y>>z;
        points[z].pb({{x,y},i+1});
    }
    solve3(points);
    return 0;
}