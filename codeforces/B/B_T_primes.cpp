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
    rep(_,n){
        ll x; cin>>x;
        if (x==1) {
            cout<<"NO"<<endl;
            continue;
        }
        int p=sqrt(x);
        if (pow(p,2)!=x){
            cout<<"NO"<<endl;
            continue;
        }
        int i=2;
        for (;i*i<=p;i++){
            if (p%i == 0) break;
        }
        if (i*i>p) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}