#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define all(c) c.begin(),c.end()
#define endl '\n'
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
#define read(a,n) rep(i,n) cin>>a[i]
#define write(a,n,s) rep(i,n) cout<<a[i]<<s;

struct useless_tree{
    int indx;
    ll m;
    ll beauty;
    int lvl;
    useless_tree* next[4];

    useless_tree(int n){
        lvl = n;
        indx = 0;
        if (n != 0){
            rep(i,4)
                next[i] = new useless_tree(n-1);
        }
    }
    void insert(ll val){
        if (lvl == 0){
            m = val;
            beauty = val;
        }
        else {
            next[indx]->insert(val);
            ++indx %= 4;
        }
    }
    ll solve(){
        if (lvl != 0) {
            m = -1;
            beauty = 0;
            rep(i,4){
                beauty += next[i]->solve();
                m = max(m,next[i]->m);
            }
            beauty += m;
        }
        return beauty;
    }
};

int main() 
{ 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int n; cin>>n;
    int a[n];
    read(a,n);
    ll x = 1;
    int m = 0;
    while (x != n){
        x<<= 2;
        m++;
    }
    useless_tree* t = new useless_tree(m);
    sort(a,a+n);

    reverse(a,a+n);
    rep(i,n){
        t->insert(a[i]);
    }
    cout<<t->solve();
    return 0;
}