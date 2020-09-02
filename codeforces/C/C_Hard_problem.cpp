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
typedef struct data {
    string x;
    bool r;
    int index;
    bool operator<(data&other){
        return other.x>x;
    }
} data;
int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin>>n;
    int c[n];
    read(n,c);
    vector<data> s;
    rep(i,n) {
        string x; cin>>x;
        data d = {x,false,i};
        s.pb(d);
        reverse(x.begin(),x.end());
        d.x=x;
        d.r = false;
        s.pb(d);
    }
    sort(s.begin(),s.end());
    
    return 0;
}