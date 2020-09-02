#include <bits/stdc++.h>
using namespace std;
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
    ll p,d; cin>>p>>d;
    ll m = 10;
    while (p % m < d) m*=10ll;
    if (m == 10) {
        cout<<p; return 0;
    }
    m/=10; ll r = p%m + 1;
    ll x = p - r,y=p;
    int i = 0, j =0;
    while (y>0 && y % 10 == 9) {
        y/=10;
        i++;
    }
    while (x>0 && x % 10 == 9) {
        x/=10;
        j++;
    }
    if (i>=j) cout<<p;
    else cout<<p-r;
    return 0;
}