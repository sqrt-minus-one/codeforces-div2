#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define endl '\n'
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define rep(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define repL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define repR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003 
typedef long long int ll; 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back 
#define pob pop_back
#define read(n,a) rep(i,n) cin>>a[i]
#define write(n,a,s) rep(i,n) cout<<a[i]<<s;

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin>>n;
    pi x[n];
    rep(i,n) cin>>x[i].F>>x[i].S;
    map<int,int> id_ord;
    map<int,int> ord_id;
    int cnt = 1;
    id_ord[0]=0;
    rep(i,n){
        if (x[i].F && id_ord.find(x[i].F)==id_ord.end()){
            id_ord[x[i].F] = cnt;
            ord_id[cnt] = x[i].F;
            cnt++;
        } 
        if (x[i].S && id_ord.find(x[i].S)==id_ord.end()){
            id_ord[x[i].S] = cnt;
            ord_id[cnt] = x[i].S;
            cnt++;
        }
    }
    int next[cnt];
    int prev[cnt];
    memset(next,-1,sizeof(next));
    memset(prev,-1,sizeof(prev));
    rep(i,n){
        next[id_ord[x[i].F]] = i;
        prev[id_ord[x[i].S]] = i;
    }
    vi res;
    int r = next[0];
    int y;
    rep(i,cnt){
        if (prev[i]==-1){
            y=i; break;
        }
    }
    res.pb(ord_id[y]);
    while (x[r].S){
        int tmp = x[r].S;
        r = next[y];
        y = id_ord[tmp];
        res.pb(tmp);
    }
    for (auto ans : res) cout<<ans<<' ';
    return 0;
}